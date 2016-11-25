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

	private:
		int StudentID;
		string StudentName;
		int Year;
		int Gender;
};

#endif /*_STUDENT_H*/
