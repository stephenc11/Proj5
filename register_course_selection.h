#ifndef _COURSE_SELECTION_H
#define _COURSE_SELECTION_H

#include <string>
#include "hashTable.h"
#include "sortedList.h"
#include "register_student.h"
#include "register_course.h"

using std::string;

class registryEntry{
	public:
		/*default constructor/destructor*/
		registryEntry();
		~registryEntry();

		int getStudentID() const;
		string getCourseCode() const;
		int getExamMark() const;

		void setStudentID(int );
		void setCourseCode(string );
		void setExamMark(int );
		
		/*
		 *bool isValidStudentID() const;
		 *bool isValidStudentName() const;
		 *bool isValidExamMark() const;
		 */

		//Need to check validity outside of the class

	private:
		int StudentID;
		string CourseCode;
		int ExamMark;				
};

class registryTable{
	public:
		/*default constructor/destructor*/
		registryTable();
		~registryTable();
		
	private:
		//container
		sortedList<registryEntry> container;		

		//two hashTable
		hashTable<registryEntry* > stu_hash;
		hashTable<registryEntry* > crs_hash;

		//pointer to student and course data
		studentTable* stu_tb;
		courseTable* crs_tb;
};

#endif /*_COURSE_SELECTION_H*/
