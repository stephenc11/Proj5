#include <cstdlib>
#include <string>
#include <cctype>
#include "register_entries.h"

/*student class*/

student::student()
:StudentID(""),StudentName(""),Year(""),Gender(""){}

student::~student(){
	StudentID.clear();
	StudentName.clear();
	Year.clear();
	Gender.clear();	
}

student::student(const string& _id, const string& _name, const string& _year, const string& _gender)
:StudentID(_id),StudentName(_name),Year(_year),Gender(_gender){}

student::student(const string& _key)
:StudentID(_key),StudentName(""),Year(""),Gender(""){}

student::student(const student& _stu)
:StudentID(_stu.StudentID),StudentName(_stu.StudentName),Year(_stu.Year),Gender(_stu.Gender){}

string student::getStudentID() const{
	return StudentID;
}

string student::getStudentName() const{
	return StudentName;
}

string student::getYear() const{
	return Year;
}

string student::getGender() const{
	return Gender;
}

string student::getKey() const{
	return StudentID; //StudentID as primary key
}

//Need to valid argument before calling set functions

void student::setStudentID(const string& _id){
		StudentID = _id;
}

void student::setStudentName(const string& _name){
		StudentName = _name;
}

void student::setYear(const string& _year){
		Year = _year;
}

void student::setGender(const string& _gender){
		Gender = _gender;
}

bool student::operator==(const student& _stu) const{
	return StudentID.compare(_stu.StudentID) == 0;
}

bool student::operator<(const student& _stu) const{
	return StudentID.compare(_stu.StudentID) < 0; 
}

bool student::isValidStudentID(const string& _id) {
	//iterater through _id to see if there is a non-digit character
	std::string::const_iterator it = _id.begin();
	while (it != _id.end() && std::isdigit(*it)) ++it;
	//determine whether _id is a numerical string with size 8
	return (_id.size() == 8) && (it == _id.end());
}

bool student::isValidStudentName(const string& _name) {
	//length of name is between 1 to 32
	return (_name.size() >= 1) && (_name.size() <= 32);
}

bool student::isValidYear(const string& _year) {
	//_year should be a numercal string with size 1
	//its range is {1,2,3} 
	if (_year.size() != 1)
		return false;

	std::string::const_iterator it = _year.begin();
	if (!(std::isdigit(*it)))
		return false;	
	else if (std::atoi(_year.c_str()) > 3 || std::atoi(_year.c_str()) < 1)
		return false;
	else
		return true;
}

bool student::isValidGender(const string& _gender) {
	//either Male or Female
	return (_gender.compare("M") == 0) || (_gender.compare("F") == 0);
}

void student::reportStudent(_IO_FILE* f) const{
	fprintf(f, "<TR>\n");
	fprintf(f, "<TD>"); fprintf(f,"%s",StudentID.c_str()); fprintf(f, "</TD>\n");
	fprintf(f, "<TD>"); fprintf(f,"%s",StudentName.c_str()); fprintf(f, "</TD>\n");
	fprintf(f, "<TD>"); fprintf(f,"%s",Year.c_str()); fprintf(f, "</TD>\n");

	if (Gender == "M"){
		fprintf(f, "<TD>"); fprintf(f,"%s","Male"); fprintf(f, "</TD>\n");
	}
	else{
		fprintf(f, "<TD>"); fprintf(f,"%s","Female"); fprintf(f, "</TD>\n");
	}
}

void student::writeToFile(_IO_FILE* f) const{
	fprintf(f,"%s",StudentID.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",StudentName.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",Year.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",Gender.c_str()); fprintf(f, "\n");
}

/*course class*/

course::course()
:CourseCode(""),CourseName(""),Credit(""){}

course::~course(){
	CourseCode.clear();
	CourseName.clear();
	Credit.clear();	
}

course::course(const string& _code, const string& _name, const string& _credit)
:CourseCode(_code),CourseName(_name),Credit(_credit){}

course::course(const string& _key)
:CourseCode(_key){}

course::course(const course& _crs)
:CourseCode(_crs.CourseCode),CourseName(_crs.CourseName),Credit(_crs.Credit){}

string course::getCourseCode() const{
	return CourseCode;
}

string course::getCourseName() const{
	return CourseName;
}

string course::getCredit() const{
	return Credit;
}

string course::getKey() const{
	return CourseCode;//CourseCode as Primary Key  
}

//Need to check argument's validity before calling set functions

void course::setCourseCode(const string& _code){
	CourseCode = _code;	
}

void course::setCourseName(const string& _name){
	CourseName = _name;
}

void course::setCredit(const string& _credit){
	Credit = _credit;
}

bool course::operator==(const course& _crs) const{
	return CourseCode.compare(_crs.CourseCode) == 0;
}

bool course::operator<(const course& _crs) const{
	return CourseCode.compare(_crs.CourseCode) < 0; 	
}

bool course::isValidCourseCode(const string& _code) {
	//check whether _code has size from 7 to 8
	if (_code.size() < 7 || _code.size() > 8)
		return false;
		
	//iterate through _code to see if it contains upper letters or digits only
	std::string::const_iterator it = _code.begin();
	while (it != _code.end() && (isdigit(*it)||isupper(*it))) ++it;
	if (it != _code.end())
		return false;
	
	//Check first four char to see if they are upper letters
	int i;
	for (i=0; i<4; i++){
		if (!isupper(_code[i]))
			return false;
	}
	
	//Otherwise return true
	return true;	
}

bool course::isValidCourseName(const string& _name) {
	return (_name.size() >= 1) && (_name.size() <= 50);
}

bool course::isValidCredit(const string& _credit) {
	//_credit should be a numercal string with size 1
	//its range is {0,1,2,3,4,5}
	if (_credit.size() != 1)
		return false;

	if (!std::isdigit(_credit[0]))
		return false;	
	else if (std::atoi(_credit.c_str()) > 5 || std::atoi(_credit.c_str()) < 0)
		return false;
	else
		return true;
}

void course::reportCourse(_IO_FILE* f) const{
	fprintf(f, "<TR>\n");
	fprintf(f, "<TD>"); fprintf(f,"%s",CourseCode.c_str()); fprintf(f, "</TD>\n");
	fprintf(f, "<TD>"); fprintf(f,"%s",CourseName.c_str()); fprintf(f, "</TD>\n");
	fprintf(f, "<TD>"); fprintf(f,"%s",Credit.c_str()); fprintf(f, "</TD>\n");
}

void course::writeToFile(_IO_FILE* f) const{
    fprintf(f,"%s",CourseCode.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",CourseName.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",Credit.c_str()); fprintf(f, "\n");
}

/*record class*/

record::record()
:StudentID(""),CourseCode(""),ExamMark("N/A"){}

record::~record(){
	StudentID.clear();
	CourseCode.clear();
	ExamMark.clear();
}

record::record(const string& _id, const string& _code, const string& _mark)
:StudentID(_id),CourseCode(_code),ExamMark(_mark){}

record::record(const string& _key1, const string& _key2)
:StudentID(_key1),CourseCode(_key2),ExamMark("N/A"){}

record::record(const record& _rcd)
:StudentID(_rcd.StudentID),CourseCode(_rcd.CourseCode),ExamMark(_rcd.ExamMark){}

string record::getStudentID() const{
	return StudentID;
}

string record::getCourseCode() const{
	return CourseCode;
}

string record::getExamMark() const{
	return ExamMark;
}

void record::setStudentID(const string& _id){
	StudentID = _id;
}

void record::setCourseCode(const string& _code){
	CourseCode = _code;
}

void record::setExamMark(const string& _mark){
	ExamMark = _mark;
}

bool record::operator==(const record& _rcd) const{
	return (StudentID.compare(_rcd.StudentID) == 0) && (CourseCode.compare(_rcd.CourseCode) == 0);	
}

bool record::operator<(const record& _rcd) const{
	return (StudentID.compare(_rcd.StudentID) == 0) ? \
		      (CourseCode.compare(_rcd.CourseCode) < 0) :\
			  (StudentID.compare(_rcd.StudentID) < 0);
}

bool record::isValidExamMark(const string& _mark){
	//ExamMark can be unassigned
	if(_mark.compare("N/A") == 0)
		return true;
	
	//_mark should be numerical
	std::string::const_iterator it = _mark.begin();
	while (it != _mark.end() && std::isdigit(*it)) ++it;
	if(it != _mark.end())
		return false;

	//mark should range from 0 to 100
	int temp = atoi(_mark.c_str());
	if (temp < 0 || temp > 100)
		return false;
	
	return true;
}

void record::writeToFile(_IO_FILE* f) const{
	fprintf(f,"%s",StudentID.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",CourseCode.c_str()); fprintf(f, "\n");
	fprintf(f,"%s",ExamMark.c_str()); fprintf(f, "\n");
	//fprintf(f,"%s",Gender.c_str()); fprintf(f, "\n");
}

/*Index class*/

Index::Index()
:_key(""){}

Index::~Index(){
	_key = "";
}

Index::Index(list<record>::iterator rcd,string str)
:_rcd(rcd),_key(str){}

Index::Index(const Index& _idx)
:_rcd(_idx._rcd),_key(_idx._key){}

string Index::getKey() const{
	return _key;
}

list<record>::iterator Index::getItr() const{
	return _rcd;
}

bool Index::operator<(const Index& idx) const{
	return _key.compare(idx._key) < 0;
}

bool Index::operator==(const Index& idx) const{
	return _key.compare(idx._key) == 0 && _rcd == idx._rcd; 
}

void Index::setKey(const string& _str){
	_key = _str;
}

/*stuIndex class*/

stuIndex::stuIndex()
:Index(){}

stuIndex::~stuIndex(){
	_key = "";
}

stuIndex::stuIndex(list<record>::iterator rcd, string str)
:Index(rcd, str){}

stuIndex::stuIndex(const stuIndex& stu_idx)
:Index(stu_idx){}

string stuIndex::getID() const{
	return _key;
}


/*crsIndex class*/

crsIndex::crsIndex()
:Index(){}

crsIndex::~crsIndex(){
	_key = "";
}

crsIndex::crsIndex(list<record>::iterator rcd, string str)
:Index(rcd, str){}

crsIndex::crsIndex(const crsIndex& crs_idx)
:Index(crs_idx){}

string crsIndex::getCode() const{
	return _key;
}

void crsIndex::report(_IO_FILE* f) const{

}