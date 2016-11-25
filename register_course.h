#ifndef _COURSE_H
#define _COURSE_H

#include <string>

using std::string;

class course{
	public:
		course();
		~course();		

	private:
		string CourseCode;
		string CourseName;		
		int Credit;
};

#endif /*_COURSE_H*/
