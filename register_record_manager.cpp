#include "register_record_manager.h"
#include "register_entries.h"
#include "html_utilities.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

/*hash functions*/

int STU_Hasher::operator() (const string& _str) const{
	//_str must be valid student ID
	long long sum = 0;
	for (int i = 7; i > -1; i--){
		sum = (_str[i]) + 10 * sum;
	}	
	return sum % 29;
}

int CRS_Hasher::operator() (const string& _str) const{
	//_str must be valid course code
	long long sum = 0;
	for (int i = _str.length() - 1; i >=0; i--){
		if(isdigit(_str[i])){
			sum = (_str[i]) + 36 * sum;
		}
		if(isupper(_str[i])){
			sum = (_str[i]-55) + 36 * sum;
		}
	}
	return sum % 17;
}

/*record manager class*/

recordManager::recordManager()
:stu_ht(29),crs_ht(17),stu_container(29),crs_container(17){
	rcd_container.clear();	
}

recordManager::~recordManager(){
	rcd_container.clear();
	stu_ht.clear();
	crs_ht.clear();
	stu_container.clear();
	crs_container.clear();
}

void recordManager::addStudent(const student& _stu){
	//Need to check whether entries are valid
	stu_container.insert(_stu);	
	//std::cout<<stu_container.size();
}

void recordManager::modifyStudent(const student& _stu){
	//Need to make sure canFind student
	stu_container.erase(_stu);
	stu_container.insert(_stu);
}

void recordManager::deleteStudent(const string& _str){
	
	//student temp(_str); //Create pseudo student with only key
	stu_container.erase(_str);//remove the student in container

	//stu_ht.find(_str);//return reg history of that student
	
	list<stuIndex > _temp (stu_ht.find(_str));	

	list<stuIndex >::iterator l_itr;
	l_itr = _temp.begin();
	
	stu_ht.erase(_str); //Remove all in stu_ht

	//remove reg history in record container
	while (l_itr != _temp.end()){
		
		crsIndex cI((l_itr->getItr()), (l_itr->getItr())->getCourseCode());
		crs_ht.erase(cI);

		rcd_container.erase((*l_itr).getItr());

		l_itr++;
	}
}

bool recordManager::canFindStudent(const string& _str) const{
	return stu_container.canFind(_str);
}

student recordManager::retrieveStudent(const string& _str) const{
	student temp(stu_container.find(_str).front());
	return temp;
}

void recordManager::addCourse(const course& _crs){
	//Need to check whether entries are valid
	crs_container.insert(_crs);
}

void recordManager::modifyCourse(const course& _crs){
	//Need to make sure canFind course
	crs_container.erase(_crs);
	crs_container.insert(_crs);
}

void recordManager::deleteCourse(const string& _crs){


	//crs_ht.find(_crs);//return reg history of that student

	list<crsIndex > _temp = crs_ht.find(_crs);	

	if (_temp.empty()){

		//list<crsIndex >::iterator l_itr;

		//l_itr = _temp.begin();

		crs_container.erase(_crs);//remove the course in container

		//crs_ht.erase(_crs); //Remove all in crs_ht

		//remove reg history in record container
		//while (l_itr != _temp.end()){

		//stuIndex sI((l_itr->getItr()), (l_itr->getItr())->getStudentID());

		//stu_ht.erase(sI);

		//rcd_container.erase((*l_itr).getItr());
		//l_itr++;
		cout<<"Deletion of course record successful"<<endl;
		cout<<endl;
		return;
	}
	else {
		cout<<"Some students already registered in this course, deletion fail"<<endl;
		cout<<endl;
		return;
	}
}


bool recordManager::canFindCourse(const string& _str) const{
	return crs_container.canFind(_str);
}

course recordManager::retrieveCourse(const string& _str) const{
	course temp(crs_container.find(_str).front());
	return temp;
}

void recordManager::addRecord(const record& _rcd){
	
	list<record>::iterator itr;
	itr = rcd_container.begin();

	while (itr != rcd_container.end())
	{
		if (*itr < _rcd)
			itr++;
		else 
			break;
	}

	record rcd(_rcd);
	
	itr = rcd_container.insert(itr, rcd);

	stuIndex sI(itr, _rcd.getStudentID());
	crsIndex cI(itr, _rcd.getCourseCode());

	stu_ht.insert(sI);
	crs_ht.insert(cI);
}

void recordManager::modifyRecord(const record& _rcd){

	list<record>::iterator itr;
	
	itr = rcd_container.begin();
	
	while (itr!= rcd_container.end()){
		if ((*itr) == _rcd){
			break;
		}
		else
			itr++;
	}
	
	itr->setExamMark(_rcd.getExamMark());
}

void recordManager::deleteRecord(const record& _rcd){

	list<record>::iterator itr;

	itr = std::find(rcd_container.begin(),rcd_container.end(),_rcd);

	stuIndex sI(itr,_rcd.getStudentID());
	crsIndex cI(itr, _rcd.getCourseCode());

	stu_ht.erase(sI);
	crs_ht.erase(cI);

	rcd_container.remove(_rcd);

}

bool recordManager::canFindRecord(const record& _rcd) const{

	list<record>::const_iterator itr;
	itr = rcd_container.begin();

	while (itr != rcd_container.end())
	{
		//cout<<"asdfasdfjkljkl"<<endl;
		if(_rcd == *itr)
			break;
		itr++;
		//cout<<"asdfasdfasdfas"<<endl;
	}
	//itr = std::find(rcd_container.begin(),rcd_container.end(), _rcd);
	return (!(itr == rcd_container.end()));
}

record recordManager::retrieveRecord(const record& _rcd) const{

	list<record>::const_iterator itr;
	itr = std::find(rcd_container.begin(),rcd_container.end(), _rcd);

	record rcd(*itr);
	return rcd;
}

void recordManager::rprtAllStudents() const{
	FILE* myfile;
	myfile = fopen("Students.html", "w+");
	printAllStuHeader(myfile);

	//Call print Functions
	list<student> temp(stu_container.getAll()); //reportStudent on everyeone

	//if empty
	if (temp.empty()){
		fprintf(myfile,"No student found\n");
	}
	//if not empty
	else{
		fprintf(myfile,"<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n");

		fprintf(myfile,"<TR>\n");
		fprintf(myfile,"<TD>Student ID</TD>\n");
		fprintf(myfile,"<TD>Student Name</TD>\n");
		fprintf(myfile,"<TD>Year</TD>\n");
		fprintf(myfile,"<TD>Gender</TD>\n");
		fprintf(myfile,"</TR>\n\n");

		list<student>::iterator itr;
		itr = temp.begin();

		while(itr!=temp.end()){
			itr->reportStudent(myfile);
			fprintf(myfile, "</TR>\n\n");
			itr++;
		}

		fprintf(myfile,"</TABLE>\n");
	}

	printTailer(myfile);

	fclose(myfile);
	
	cout <<"Output Successful"<<endl;
	cout<<endl;
	cout <<"Hit ENTER to continue..."<<endl;

	string s;
	getline(cin, s);

	return;
}

void recordManager::rprtAllCourses() const{

	FILE* myfile;
	myfile = fopen("Courses.html", "w+");
	printAllCrsHeader(myfile);

	//Call print Functions
	list<course> temp(crs_container.getAll()); //reportStudent on everyeone

	//if empty
	if (temp.empty()){

		fprintf(myfile,"No course found\n");

	}
	//if not empty
	else{

		fprintf(myfile,"<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n");

		fprintf(myfile,"<TR>\n");
		fprintf(myfile,"<TD>Course Code</TD>\n");
		fprintf(myfile,"<TD>Course Name</TD>\n");
		fprintf(myfile,"<TD>Credit</TD>\n");

		fprintf(myfile,"</TR>\n\n");

		list<course>::iterator itr;
		itr = temp.begin();

		while(itr!=temp.end()){
			itr->reportCourse(myfile);
			fprintf(myfile, "</TR>\n\n");
			itr++;
		}

		fprintf(myfile,"</TABLE>\n");
	}

	printTailer(myfile);

	fclose(myfile);
	
	cout <<"Output Successful"<<endl;
	cout<<endl;
	cout <<"Hit ENTER to continue..."<<endl;

	string s;
	getline(cin, s);

	return;
}

void recordManager::rprtAllStudents(const string& _str) const{
	
	if (!canFindCourse(_str)){
		cout <<"Course not exist"<<endl;
		cout<<endl;
		cout <<"Hit ENTER to continue..."<<endl;

		string s;
		getline(cin, s);

		return;
	}

	FILE* myfile;
	string filename = _str + ".html";
	myfile = fopen(filename.c_str(), "w+");

	printCrsHeader(myfile, retrieveCourse(_str));

	//Call print Functions
	list<crsIndex > temp = crs_ht.find(_str); //reportStudent on everyeone

	//if empty
	if (temp.empty()){
		fprintf(myfile,"No student found\n");
	}
	//if not empty
	else{
		fprintf(myfile,"<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n");

		fprintf(myfile,"<TR>\n");
		fprintf(myfile,"<TD>Student ID</TD>\n");
		fprintf(myfile,"<TD>Student Name</TD>\n");
		fprintf(myfile,"<TD>Year</TD>\n");
		fprintf(myfile,"<TD>Gender</TD>\n");
		fprintf(myfile,"<TD>Exam Mark</TD>\n");
		fprintf(myfile,"</TR>\n\n");

		list<crsIndex >::iterator itr;
		itr = temp.begin();

		while(itr!=temp.end()){
			
			list<record>::iterator _itr;
			_itr = itr->getItr();

			string cc = _itr->getStudentID();

			retrieveStudent(cc).reportStudent(myfile);

			fprintf(myfile,"<TD>"); fprintf(myfile,"%s",_itr->getExamMark().c_str());fprintf(myfile,"</TD>\n");

			fprintf(myfile,"</TR>\n\n");
			itr++;
		}

		fprintf(myfile,"</TABLE>\n");
	}

	printTailer(myfile);

	fclose(myfile);
	
	cout <<"Output Successful"<<endl;
	cout<<endl;
	cout <<"Hit ENTER to continue..."<<endl;

	string s;
	getline(cin, s);

	return;
}

void recordManager::rprtAllCourses(const string& _str) const{
	
	if (!canFindStudent(_str)){
		cout <<"Student not exist"<<endl;
		cout<<endl;
		cout <<"Hit ENTER to continue..."<<endl;

		string s;
		getline(cin, s);

		return;
	}

	FILE* myfile;
	string filename = _str + ".html";
	myfile = fopen(filename.c_str(), "w+");

	printStuHeader(myfile, retrieveStudent(_str));

	//Call print Functions
	list<stuIndex > temp = stu_ht.find(_str); //reportStudent on everyeone

	//if empty
	if (temp.empty()){
		fprintf(myfile,"No course found\n");
	}
	//if not empty
	else{

		fprintf(myfile,"<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n");
		
		fprintf(myfile,"<TR>\n");
		fprintf(myfile,"<TD>Course Code</TD>\n");
		fprintf(myfile,"<TD>Course Name</TD>\n");
		fprintf(myfile,"<TD>Credit</TD>\n");
		fprintf(myfile,"<TD>Exam Mark</TD>\n");
		fprintf(myfile,"</TR>\n\n");

		list<stuIndex >::iterator itr;
		itr = temp.begin();

		while(itr!=temp.end()){

			//course crs( retrieveCourse((itr->getItr())->getCourseCode()) );
			//crs.reportCourse(myfile);

			list<record>::iterator _itr;
			_itr = itr->getItr();

			string cc = _itr->getCourseCode();

			retrieveCourse(cc).reportCourse(myfile);

			fprintf(myfile,"<TD>"); fprintf(myfile,"%s",_itr->getExamMark().c_str());fprintf(myfile,"</TD>\n");

			fprintf(myfile,"</TR>\n\n");
			itr++;
		}

		fprintf(myfile,"</TABLE>\n");
	}

	printTailer(myfile);

	fclose(myfile);
	
	cout <<"Output Successful"<<endl;
	cout<<endl;
	cout <<"Hit ENTER to continue..."<<endl;

	string s;
	getline(cin, s);

	return;
}

void recordManager::saveFile() const{

	cout<<"Enter the file name: ";
	string s;
	getline(cin, s);

	FILE* myfile;
	myfile = fopen(s.c_str(), "w+");

	if (myfile == NULL){
		cout <<"Error: Write File Error"<<endl;
		cout<<endl;
		cout <<"Hit ENTER to continue..."<<endl;

		getline(cin, s);

		return;
	}

	list<student> stu_temp(stu_container.getAll());
	list<course> crs_temp(crs_container.getAll());

	list<student>::const_iterator stu_itr;
	list<course>::const_iterator crs_itr;
	list<record>::const_iterator rcd_itr;

	stu_itr = stu_temp.begin();
	crs_itr = crs_temp.begin();
	rcd_itr = rcd_container.begin();

	while(stu_itr != stu_temp.end()){
		stu_itr->writeToFile(myfile);
		stu_itr++;
	}

	fprintf(myfile,"\n");
	while(crs_itr != crs_temp.end()){
		crs_itr->writeToFile(myfile);
		crs_itr++;
	} 

	fprintf(myfile,"\n");
	while(rcd_itr != rcd_container.end()){
		rcd_itr->writeToFile(myfile);
		rcd_itr++;
	}

	fclose(myfile);

	cout <<"Saving Successful"<<endl;
	cout<<endl;
	cout <<"Hit ENTER to continue..."<<endl;

	getline(cin, s);

	return;
}

void recordManager::loadFile() {

	cout<<"Enter the file name: ";
	string s;
	getline(cin, s);

	ifstream fin;
	fin.open(s.c_str());

	if (!fin.is_open()){

		cout <<"Error: Load File Error (File not exist / File Corrupted / Incorrect Format)"<<endl;
		cout<<endl;
		cout <<"Hit ENTER to continue..."<<endl;

		getline(cin, s);

		return;
	}

	stu_container.clear();
	crs_container.clear();
	stu_ht.clear();
	crs_ht.clear();
	rcd_container.clear();

	string c_temp1, c_temp2, c_temp3, c_temp4;

	while(1){
		getline(fin,c_temp1);
		if(c_temp1.size() != 0){
			getline(fin,c_temp2);
			getline(fin,c_temp3);
			getline(fin,c_temp4);
			student stu(c_temp1, c_temp2, c_temp3, c_temp4);
			addStudent(stu);
		}
		else break;
	}

	while(1){
		getline(fin,c_temp1);
		if(c_temp1.size() != 0){
			getline(fin,c_temp2);
			getline(fin,c_temp3);
			//getline(fin,c_temp4);
			course crs(c_temp1, c_temp2, c_temp3);
			addCourse(crs);
		}
		else break;
	}

	while(1){
		getline(fin,c_temp1);
		if(c_temp1.size() != 0){
			getline(fin,c_temp2);
			getline(fin,c_temp3);
			//getline(fin,c_temp4);
			record rcd(c_temp1, c_temp2, c_temp3);
			addRecord(rcd);
		}
		else break;
	}

	fin.close();

	cout <<"Loading Successful"<<endl;
	cout<<endl;
	cout <<"Hit ENTER to continue..."<<endl;

	getline(cin, s);

	return;
}