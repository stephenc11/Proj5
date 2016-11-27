#ifndef _RECORD_MANAGER_H
#define _RECORD_MANAGER_H

#include <string>
#include "hashTable.h"
#include "sortedList.h"
#include "register_entries.h"

using std::string;

class recordManager{
	public:
		/*default constructor/destructor*/
		recordManager();
		~recordManager();
	
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
	
		void addRecord(const record& );
		void deleteRecord(const record& );
		void modifyRecord(const record& );

		bool canFindRecord(const record& ) const;

		//saveFile(const string& ) const;
		//loadFile(const string& ) const;
		//getAllStudents const
		//getAllCourses const	
			
	private:
		//container
		sortedList<record> rcd_container; //container of course record		

		//two hashTable
		hashTable<record* > stu_hash;
		hashTable<record* > crs_hash;

		//pointer to student and course data
		hashTable<student> stu_container;
		hashTable<course> crs_container;
};

#endif /*_RECORD_MANEGER_H*/