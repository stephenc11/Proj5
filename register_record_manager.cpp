#include "register_record_manager.h"
#include <cstdlib>

int STU_Hasher::operator() (const string& _str){
	//_str must be valid student ID
	long sum = 0;
	for (int i = 0; i < 8; i++){
		sum += (_str[i])*((long)pow(10,i));
	}	
	return sum % 29;
}

int CRS_Hasher::operator() (const string& _str){
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
:stu_hash(29),crs_hash(17),stu_container(29),crs_container(17){
	rcd_container.clear();	
}

recordManager::~recordManager(){
	rcd_container.clear();
	stu_hash.clear();
	crs_hash.clear();
	stu_container.clear();
	crs_container.clear();
}

void recordManager::addStudent(const student& _stu){
	//Need to check whether entries are valid
	stu_container.insert(_stu,_stu.getKey());	
}

void recordManager::modifyStudent(const student& _stu){
	list<student& > ls = stu_container.find(_stu);	
	ls.at(0) = _stu;
}


