#ifndef _RECORD_MANAGER_H
#define _RECORD_MANAGER_H

#include <string>
#include <list>
#include "hashTable.h"
#include "register_entries.h"

using std::string;

/*unary hash functions*/
struct STU_Hasher{
	int operator() (const string&  ) const;
};

struct CRS_Hasher{
	int operator() (const string& ) const;
};

/*record manager class*/
class recordManager{
	public:
		/*default constructor/destructor*/
		recordManager();
		~recordManager();
	
		void addStudent(const student&);	
		void modifyStudent(const student&);
		void deleteStudent(const string&);

		bool canFindStudent(const string&) const;
		student retrieveStudent(const string& ) const;
		
		void addCourse(const course&);
		void modifyCourse(const course&);
	    void deleteCourse(const string&);			
		
		bool canFindCourse(const string&) const;	
		course retrieveCourse(const string&) const;
	
		void addRecord(const record& );
		void deleteRecord(const record& );
		void modifyRecord(const record& );//Change ExamScore 

		bool canFindRecord(const record& ) const;
		record retrieveRecord(const record& ) const;
		
		/*IO with database*/
		void saveFile() const;
		void loadFile();
		//test loading and return validity
		bool testLoad(const string& ) const;	

		//report All students
		void rprtAllStudents() const;
		//report All courses
		void rprtAllCourses() const;
		//report All students in a course
		void rprtAllStudents(const string& ) const; 
		//report All courses for a student
		void rprtAllCourses(const string& )	const; 		

	private:
		//container
		list<record> rcd_container; //container of course enrollment record		
		//two hashTables of Indices
		hashTable<stuIndex, STU_Hasher> stu_ht;
		hashTable<crsIndex, CRS_Hasher> crs_ht;

		//containers of student and course data
		hashTable<student, STU_Hasher> stu_container;
		hashTable<course, CRS_Hasher> crs_container;
};


#endif /*_RECORD_MANEGER_H*/
