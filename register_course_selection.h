#ifndef _COURSE_SELECTION_H
#define _COURSE_SELECTION_H

#include <cstring>
#include "hashTable.h"
#include "sortedList.h"

using std::string;

class registryEntry{
	public:
		/*default constructor/destructor*/
		registryEntry();
		~registryEntry();

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
		sortedList<registryEntry> container;		
		//two hash Table
};

#endif /*_COURSE_SELECTION_H*/
