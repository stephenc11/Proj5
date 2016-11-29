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

bool student::isValidStudentID(const string& _id) const{
	//iterater through _id to see if there is a non-digit character
	std::string::const_iterator it = _id.begin();
	while (it != _id.end() && std::isdigit(*it)) ++it;
	//determine whether _id is a numerical string with size 8
	return (_id.size() == 8) && (it == _id.end());
}

bool student::isValidStudentName(const string& _name) const{
	//length of name is between 1 to 32
	return (_name.size() >= 1) && (_name.size() <= 32);
}

bool student::isValidYear(const string& _year) const{
	//_year should be a numercal string with size 1
	//its range is {1,2,3,4,5} (including five year program)
	if (_year.size() != 1)
		return false;

	std::string::const_iterator it = _year.begin();
	if (!(std::isdigit(*it)))
		return false;	
	else if (std::atoi(_year.c_str()) > 5 || std::atoi(_year.c_str()) < 1)
		return false;
	else
		return true;
}

bool student::isValidGender(const string& _gender) const{
	//either Male or Female
	return (_gender.compare("Male") == 0) || (_gender.compare("Female") == 0);
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

bool course::isValidCourseCode(const string& _code) const{
	//check whether _code has size from 7 to 9
	if (_code.size() < 7 || _code.size() > 9)
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

bool course::isValidCourseName(const string& _name) const{
	return (_name.size() >= 1) && (_name.size() <= 50);
}

bool course::isValidCredit(const string& _credit) const{
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

/*record class*/

record::record()
:StudentID(""),CourseCode(""),ExamMark(""){}

record::~record(){
	StudentID.clear();
	CourseCode.clear();
	ExamMark.clear();
}

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
	return (StudentID.compare(_rcd.StudentID) == 0) && \
			(CourseCode.compare(_rcd.CourseCode) == 0);	
}

bool record::operator<(const record& _rcd) const{
	return (StudentID.compare(_rcd.StudentID) == 0) ? \
		      (CourseCode.compare(_rcd.CourseCode) < 0) :\
			  (StudentID.compare(_rcd.StudentID) < 0);
}

bool record::isValidExamMark(const string& _mark) const{
	//ExamMark can be unassigned
	if(_mark.compare("") == 0)
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

/*Index class*/

Index::Index()
:_rcd(0),_key(""){}

Index::~Index(){
	_rcd = 0;
	_key = "";
}

Index::Index(record* rcd,string str)
:_rcd(rcd),_key(str){}

string Index::getKey() const{
	return _key;
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
	_rcd = 0;
	_key = "";
}

stuIndex::stuIndex(record* rcd, string str)
:Index(rcd, str){};

string stuIndex::getID() const{
	return _key;
}

/*crsIndex class*/

crsIndex::crsIndex()
:Index(){}

crsIndex::~crsIndex(){
	_rcd = 0;
	_key = "";
}

crsIndex::crsIndex(record* rcd, string str)
:Index(rcd, str){};

string crsIndex::getCode() const{
	return _key;
}

