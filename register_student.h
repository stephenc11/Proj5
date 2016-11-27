#ifndef _STUDENT_H
#define _STUDENT_H

#include "hashTable.h"
#include "sortedList.h"
#include <string>

using std::string;

class student{
	public:
		/*default constructor/destructor*/
		student();
		~student();
	    
		//Student::Student(_IO_FILE*)
		
		student(string& ,string&, string& ,string& );
	
		//student::writeToFile(_IO_FILE*) const
		
		int getStudentID() const;
		string getStudentName() const;
		int getYear() const;
		char getGender() const;

		void setStudentID(int );
		void setStudentName(string );
		void setYear(int );
		void setGender(char );
	
		bool isValidStudentID(int ) const;
		bool isValidStudentName(string ) const;
		bool isValidYear(int ) const;
		bool isValidGender(char ) const;

		bool operator==(const student& ) const;//only check key
		bool operator<(const student& ) const;

	private:
		string StudentID;
		string StudentName;
		string Year;
		string Gender;//M or F
};

class studentTable{
	public:
		/*default constructor/destructor*/
		studentTable();
		~studentTable();

	private:
		hashTable<student> stu_container;		
};

#endif /*_STUDENT_H*/
