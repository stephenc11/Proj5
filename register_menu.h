#include "register_entries.h"
#include "register_record_manager.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


struct Menu{

	void RunStuMenu();
	void RunCrsMenu();
	void RunRegMenu();
	void RunRprtMenu();
	void RunFileMenu();

	void InsertStuRcd();
	void ModifyStuRcd();
	void DeleteStuRcd();
	void QueryStuRcd();
	
	void InsertCrsRcd();
	void ModifyCrsRcd();
	void DeleteCrsRcd();
	void QueryCrsRcd();

	void AddCourse();
	void DropCourse();
	void ModifyExamMark();
	void QueryReg();

	string AskforStuName();
	string AskforYear();
	string AskforGender();

	string AskforCrsName();
	string AskforCredit();

	string AskforMark();
	string AskforCrsCode();
	string AskforStuID();

	recordManager RcdMng;
};

void Menu::RunStuMenu(){

	system("clear");

	cout<<"HKUST Course Registration System  (Student Menu)"<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"1. Insert Student Record"<<endl;
	cout<<"2. Modify Student Record"<<endl;
	cout<<"3. Delete Student Record"<<endl;
	cout<<"4. Query Student Record"<<endl;
	cout<<"5. Go back to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your choice (1-5): ";
	
	while(1){
	
	string choice;
	getline(cin,choice);
	int co1 = atoi(choice.c_str()); 

	switch(co1){
		case 1:
			InsertStuRcd();
			return;	

		case 2:
			ModifyStuRcd();
			return;
		
		case 3:
			DeleteStuRcd();
			return;

		case 4:
			QueryStuRcd();
			return;

		case 5:			
			return;

		default:
			cout<<"Invalid input, re-enter again (1-5): ";
	}
	}	
}

void Menu::RunCrsMenu(){

	system("clear");

	cout<<"HKUST Course Registration System  (Course Menu)"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<endl;
	cout<<"1. Insert Course Record"<<endl;
	cout<<"2. Modify Course Record"<<endl;
	cout<<"3. Delete Course Record"<<endl;
	cout<<"4. Query Course Record"<<endl;
	cout<<"5. Go back to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your choice (1-5): ";
	
	while(1){
	
	string choice;
	getline(cin,choice);
	int co1 = atoi(choice.c_str()); 

	switch(co1){
		case 1:
			InsertCrsRcd();
			return;	

		case 2:
			ModifyCrsRcd();
			return;
		
		case 3:
			DeleteCrsRcd();
			return;

		case 4:
			QueryCrsRcd();
			return;

		case 5:			
			return;

		default:
			cout<<"Invalid input, re-enter again (1-5): ";
	}
	}	
}

void Menu::RunRegMenu(){

	system("clear");

	cout<<"HKUST Course Registration System  (Registration Menu)"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"1. Add Course"<<endl;
	cout<<"2. Drop Course"<<endl;
	cout<<"3. Modify Exam Mark"<<endl;
	cout<<"4. Query Registration"<<endl;
	cout<<"5. Go back to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your choice (1-5): ";
	
	while(1){
	
	string choice;
	getline(cin,choice);
	int co1 = atoi(choice.c_str()); 

	switch(co1){
		case 1:
			AddCourse();
			return;	

		case 2:
			DropCourse();
			return;
		
		case 3:
			ModifyExamMark();
			return;

		case 4:
			QueryReg();
			return;

		case 5:			
			return;

		default:
			cout<<"Invalid input, re-enter again (1-5): ";
	}
	}	
}

void Menu::RunFileMenu(){
	
	system("clear");

	cout<<"HKUST Course Registration System  (File Menu)"<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<endl;
	cout<<"1. Save Database"<<endl;
	cout<<"2. Load Database"<<endl;
	cout<<"3. Go back to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your choice (1-3): ";

	while(1){
	
	string choice;
	getline(cin,choice);
	int co1 = atoi(choice.c_str()); 

	switch(co1){
		case 1:

			return;
		case 2:

			return;

		case 3:
			return;

		default:
			cout<<"Invalid input, re-enter again (1-3): ";
	}
	}
}

void Menu::RunRprtMenu(){
	
	system("clear");
				
	cout<<"HKUST Course Registration System  (Report Generation Menu)"<<endl;
	cout<<"----------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"1. List all student information"<<endl;
	cout<<"2. List all course information"<<endl;
	cout<<"3. List all courses of a student"<<endl;
	cout<<"4. List all students of a course"<<endl;
	cout<<"5. Go back to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your choice (1-5): ";

	while(1){
	
	string choice;
	getline(cin,choice);
	int co1 = atoi(choice.c_str()); 

	switch(co1){
		case 1:
			RcdMng.rprtAllStudents();
			return;
		case 2:
			RcdMng.rprtAllCourses();
			return;

		case 3:
			cout<<"Enter the student ID: ";
			RcdMng.rprtAllCourses(AskforStuID());
			return;

		case 4:
			cout<<"Enter the course code: ";
			RcdMng.rprtAllStudents(AskforCrsCode());
			return;

		case 5:
			return;

		default:
			cout<<"Invalid input, re-enter again (1-5): ";
	}
	}
}

void Menu::InsertStuRcd(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (RcdMng.canFindStudent(s)) 
			{
				cout<<"Student already exists"<<endl;
				cout<<endl;
			}

			else{
				const string id(s);
				cout<<"Enter the student name: ";
				const string name(AskforStuName());
				cout<<"Enter the student year [1-3]: ";
				const string year(AskforYear());
				cout<<"Enter the student gender [M,F]: ";
				const string gender(AskforGender());
				student stu(id,name,year,gender);
				RcdMng.addStudent(stu);
				cout<<"Creation of student record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::ModifyStuRcd(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				student stu(RcdMng.retrieveStudent(id));
				cout<<"Enter the student name ["<<stu.getStudentName()<<"]: ";
				const string name(AskforStuName());
				cout<<"Enter the student year ["<<stu.getYear()<<"]: ";
				const string year(AskforYear());
				cout<<"Enter the student gender ["<<stu.getGender()<<"] :";
				const string gender(AskforGender());
				student stu1(id,name,year,gender);
				RcdMng.modifyStudent(stu1);
				cout<<"Modification of student record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::DeleteStuRcd(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				RcdMng.deleteStudent(id);
				cout<<"Deletion of student record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::QueryStuRcd(){
	
	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				student stu(RcdMng.retrieveStudent(id));
				cout<<endl;
				cout<<"ID:     "<<stu.getStudentID()<<endl;
				cout<<"Name:   "<<stu.getStudentName()<<endl;
				cout<<"Year:   "<<stu.getYear()<<endl;
				cout<<"Gender: "<<stu.getGender()<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}	

}

void Menu::InsertCrsRcd(){

	cout<<"Enter the course code: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseCode(s)){

			if (RcdMng.canFindCourse(s)) 
			{
				cout<<"Course already exists"<<endl;
				cout<<endl;
			}

			else{
				const string code(s);
				cout<<"Enter the course name: ";
				const string name(AskforCrsName());
				cout<<"Enter the course credit [0-5]: ";
				const string cred(AskforCredit());
				
				course crs(code, name, cred);
				RcdMng.addCourse(crs);
				cout<<"Creation of course record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [course code]: ";
		}
	}
}

void Menu::ModifyCrsRcd(){

	cout<<"Enter the course code: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseCode(s)){

			if (!(RcdMng.canFindCourse(s))) 
			{
				cout<<"Course not exist"<<endl;
				cout<<endl;
			}
			else{
				const string code(s);
				course crs(RcdMng.retrieveCourse(code));

				cout<<"Enter the course name ["<<crs.getCourseName()<<"]: ";
				const string name(AskforCrsName());

				cout<<"Enter the credit ["<<crs.getCredit()<<"]: ";
				const string cred(AskforCredit());
			
				course crs1(code,name,cred);
				RcdMng.modifyCourse(crs1);
				cout<<"Modification of course record successful"<<endl;
				cout<<endl;
			}

			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [course code]: ";
		}
	}

}

void Menu::DeleteCrsRcd(){
	cout<<"Enter the course code: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseCode(s)){

			if (!(RcdMng.canFindCourse(s))) 
			{
				cout<<"Course not exist"<<endl;
				cout<<endl;
			}
			else{
				const string code(s);
				RcdMng.deleteCourse(code);
				cout<<"Deletion of course record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [course code]: ";
		}
	}

}

void Menu::QueryCrsRcd(){

	cout<<"Enter the course code: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseCode(s)){

			if (!(RcdMng.canFindCourse(s))) 
			{
				cout<<"Course not exist"<<endl;
				cout<<endl;
			}
			else{
				const string code(s);
				course crs(RcdMng.retrieveCourse(code));
				cout<<endl;
				cout<<"Code:     "<<crs.getCourseCode()<<endl;
				cout<<"Name:     "<<crs.getCourseName()<<endl;
				cout<<"Credit:   "<<crs.getCredit()<<endl;
				
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [course code]: ";
		}
	}

}

string Menu::AskforStuName(){
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentName(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [student name]: ";
		}
	}
}

string Menu::AskforYear(){
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidYear(s)){
			return s; 	
		}

		else{
			cout<<"Invalid input, re-enter again [student year]: ";
		}
	}
}

string Menu::AskforGender(){
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidGender(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [M,F]: ";
		}
	}
}

string Menu::AskforCrsName(){

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseName(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [course name]: ";
		}
	}
}

string Menu::AskforCredit(){

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCredit(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [course credit]: ";
		}
	}
}

string Menu::AskforCrsCode(){

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseName(s)){
				return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [course code]: ";
		}
	}
}

string Menu::AskforMark(){

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(record::isValidExamMark(s)){
				return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [exam mark]: ";
		}
	}
}

string Menu::AskforStuID(){
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){
				return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [exam mark]: ";
		}
	}
}

void Menu::AddCourse(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else
			{
				const string id(s);
				cout<<"Enter the course code: ";
				string temp = AskforCrsCode();
				const string code(temp);
				//cout<<"asdasdasd"<<endl;
				if(!(RcdMng.canFindCourse(code))){
					cout<<"Course not exist"<<endl;
					cout<<endl;
				}
				else{
					//cout<<"hihihihihihihhi"<<endl;
					record rcd(id, code);
					if(!(RcdMng.canFindRecord(rcd))){
						RcdMng.addRecord(rcd);
						cout<<"Add course successful"<<endl;
						cout<<endl;
					}
					else{
						cout<<"Record already exists"<<endl;
						cout<<endl;
					}
				}
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::DropCourse(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				cout<<"Enter the course code: ";
				const string code(AskforCrsCode());
				if(!RcdMng.canFindCourse(code)){
					cout<<"Course not exist"<<endl;
					cout<<endl;
				}
				else{
					record rcd(id, code);
					if(RcdMng.canFindRecord(rcd)){
						RcdMng.deleteRecord(rcd);
						cout<<"Drop course successful"<<endl;
						cout<<endl;
					}
					else{
						cout<<"Record not exist"<<endl;
						cout<<endl;
					}
				}
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::ModifyExamMark(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				cout<<"Enter the course code: ";
				const string code(AskforCrsCode());
				if(!RcdMng.canFindCourse(code)){
					cout<<"Course not exist"<<endl;
					cout<<endl;
				}
				else{
					record rcd(id, code);
					if(RcdMng.canFindRecord(rcd)){
						record _rcd(RcdMng.retrieveRecord(rcd));

						cout<<"Enter the exam mark ["<<_rcd.getExamMark()<<"]: ";
						const string mark(AskforMark());

						record __rcd(id,code,mark);
						RcdMng.modifyRecord(__rcd);

						cout<<"Modification of Exam Mark successful"<<endl;
						cout<<endl;
					}
					else{
						cout<<"Record not exist"<<endl;
						cout<<endl;
					}
				}
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}

}

void Menu::QueryReg(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				cout<<"Enter the course code: ";
				const string code(AskforCrsCode());
				if(!RcdMng.canFindCourse(code)){
					cout<<"Course not exist"<<endl;
					cout<<endl;
				}
				else{
					record rcd(id, code);
					if(RcdMng.canFindRecord(rcd)){

						record _rcd(RcdMng.retrieveRecord(rcd));
						cout<<endl;
						cout<<"Student ID:  "<<_rcd.getStudentID()<<endl;
						cout<<"Course Code: "<<_rcd.getCourseCode()<<endl;
						cout<<"Exam Mark:   "<<_rcd.getExamMark()<<endl;
						cout<<endl;
					}
					else{
						cout<<"Record not exist"<<endl;
						cout<<endl;
					}
				}
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}