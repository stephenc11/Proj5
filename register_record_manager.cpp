#include "register_record_manager.h"
#include "register_entries.h"
#include <cstdlib>
#include <cmath>

/*hash functions*/

int STU_Hasher::operator() (const string& _str) const{
	//_str must be valid student ID
	long sum = 0;
	for (int i = 0; i < 8; i++){
		sum += (_str[i])*((long)pow(10,i));
	}	
	return sum % 29;
}

int CRS_Hasher::operator() (const string& _str) const{
	//_str must be valid course code
	long sum = 0;
	for (unsigned int i = 0; i < _str.length(); i++){
		if(isdigit(_str[i])){
			sum += (_str[i])*((long)pow(36,i));
		}
		if(isupper(_str[i])){
			sum += (_str[i]-55)*((long)pow(36,i));
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
		rcd_container.erase((*l_itr).getItr());
		l_itr++;
	}
}
