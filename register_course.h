#ifndef _COURSE_H
#define _COURSE_H

#include <string>
#include "hashTable.h"

using std::string;

class course{
	public:
		course();
		~course();		
		
		course(string&, string& ,string& );

		string getCourseCode() const;
		string getCourseName() const;
		int getCredit() const;
		
		void setCourseCode(string );
		void setCourseName(string );
		void setCredit(int );

		bool isValidCourseCode(string ) const;
		bool isValidCourseName(string ) const;
		bool isValidCredit(int ) const;

		bool operator==(const course& ) const; //only check key
		bool operator<(const course& ) const;	
		
		//Course(_IO_FILE*)
		//writeToFile(_IO_FILE*) const
		
	private:
		string CourseCode;
		string CourseName;		
		int Credit;
};

class courseTable{
	public:
		courseTable();
		~courseTable();
		
	private:
		hashTable<course> crs_container;
};

#endif /*_COURSE_H*/
