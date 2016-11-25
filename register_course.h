#ifndef _COURSE_H
#define _COURSE_H

#include <string>
#include "hashTable.h"

using std::string;

class course{
	public:
		course();
		~course();		

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
