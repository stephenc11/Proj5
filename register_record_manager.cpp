#include "register_record_manager.h"
#include "register_entries.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

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
	for (unsigned int i = _str.length() - 1; i > -1; i--){
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
}

void recordManager::modifyStudent(const student& _stu){
	//Need to make sure canFind student
	stu_container.erase(_stu);
	stu_container.insert(_stu);
}

void recordManager::deleteStudent(const string& _str){
	
	student temp(_str); //Create pseudo student with only key
	stu_container.erase(temp);//remove the student in container

	stu_ht.find(_str);//return reg history of that student

	list<stuIndex > _temp = stu_ht.find(_str);	
	list<stuIndex >::iterator l_itr;
	l_itr = _temp.begin();
	
	stu_ht.erase(_str); //Remove all in stu_ht

	//remove reg history in record container
	while (l_itr != _temp.end()){
		//crs_ht.erase((*((*l_itr).getItr())).getCourseCode());
		//crsIndex()
		crsIndex cI(((*l_itr).getItr()), ((*l_itr).getItr())->getCourseCode());

		crs_ht.erase(cI);
		rcd_container.erase((*l_itr).getItr());
		l_itr++;
	}
}

bool recordManager::canFindStudent(const string& _str) const{
	return stu_container.canFind(_str);
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
	
	course temp(_crs); //Create pseudo student with only key
	crs_container.erase(temp);//remove the student in container

	crs_ht.find(_crs);//return reg history of that student

	list<crsIndex > _temp = crs_ht.find(_crs);	
	list<crsIndex >::iterator l_itr;
	l_itr = _temp.begin();
	
	crs_ht.erase(_crs); //Remove all in stu_ht

	//remove reg history in record container
	while (l_itr != _temp.end()){

		stuIndex sI(((*l_itr).getItr()), ((*l_itr).getItr())->getStudentID());

		stu_ht.erase(sI);
		rcd_container.erase((*l_itr).getItr());
		l_itr++;

	}
}

void recordManager::addRecord(const record& _rcd){
	
	list<record>::iterator itr;
	itr = rcd_container.begin();

	while (itr!= rcd_container.end()){
		if (*itr < _rcd){
			itr++;
		}
	}

	itr = rcd_container.insert(itr, _rcd);

	stuIndex sI(itr, _rcd.getStudentID());
	crsIndex cI(itr, _rcd.getCourseCode());

	stu_ht.insert(sI);
	crs_ht.insert(cI);
}

void recordManager::modifyRecord(const record& _rcd){

	list<record>::iterator itr;
	
	while (itr!= rcd_container.end()){
		if (*itr == _rcd){
			itr++;
		}
	}
	
	itr->setExamMark(_rcd.getExamMark());

}

void recordManager::deleteRecord(const record& _rcd){

	stu_ht.erase(_rcd.getStudentID());
	crs_ht.erase(_rcd.getCourseCode());

	rcd_container.remove(_rcd);

}

bool recordManager::canFindRecord(const record& _rcd) const{

	list<record>::const_iterator itr;
	itr = std::find(rcd_container.begin(),rcd_container.end(), _rcd);
	return (itr!= rcd_container.end());

}
