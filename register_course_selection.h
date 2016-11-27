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
		
		//writeToFile(_IO_FILE*) const/
	
		bool operator==(const registryEntry& ) const;
		bool operator<(const registryEntry& ) const;	
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
	
		void addStudent(const student&);	
		void modifyStudent(const student&);
		void deleteStudent(const string&);

		bool canFindStudent(const string&) const;
		//void retrieveStudent(const string&, student&) const;
		
		void addCourse(const course&);
		void modifyCourse(const course&);
	    void deleteCourse(const string&);			
		
		bool canFindCourse(const string&) const;	
		//void retrieveCourse(const string&, course&) const;
	
		void addRegistry(const registryEntry& );
		void deleteRegistry(const registryEntry& );
		void modifyRegistry(const registryEntry& );

		bool canFindRegistry(const registryEntry& ) const;

		//saveFile(const string& ) const;
		//loadFile(const string& ) const;
		//getAllStudents const
		//getAllCourses const

		
			
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
