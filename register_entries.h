#ifndef _ENTRIES_H
#define _ENTRIES_H

#include <string>

using std::string;

class student{
	public:
		/*default constructor/destructor*/
		student();
		~student();
		
		//conversion constructor
		student(const string& _id,const string& _name,const string& _year,const string& _gender);
	
		string getStudentID() const;
		string getStudentName() const;
		string getYear() const;
		string getGender() const;

		void setStudentID(const string& );
		void setStudentName(const string& );
		void setYear(const string& );
		void setGender(const string& );
	
		bool operator==(const student& ) const;//only check key
		bool operator<(const student& ) const;
		
		bool isValidStudentID(const string& ) const;
		bool isValidStudentName(const string& ) const;
		bool isValidYear(const string& ) const;
		bool isValidGender(const string& ) const;

		//Student::Student(_IO_FILE*)
		//student::writeToFile(_IO_FILE*) const
		
	private:
		string StudentID;
		string StudentName;
		string Year;
		string Gender;//M or F
};


class course{
	public:
		course();
		~course();		
		
		course(const string& ,const string& ,const string& );

		string getCourseCode() const;
		string getCourseName() const;
		string getCredit() const;
		
		void setCourseCode(const string& );
		void setCourseName(const string& );
		void setCredit(const string& );

		bool operator==(const course& ) const; //only check key
		bool operator<(const course& ) const;	
		
		bool isValidCourseCode(const string& ) const;
		bool isValidCourseName(const string& ) const;
		bool isValidCredit(const string& ) const;

		//Course(_IO_FILE*)
		//writeToFile(_IO_FILE*) const
		
	private:
		string CourseCode;
		string CourseName;		
		string Credit;
};


class record{
	public:
		/*default constructor/destructor*/
		record();
		~record();

		string getStudentID() const;
		string getCourseCode() const;
		string getExamMark() const;

		void setStudentID(const string&  );
		void setCourseCode(const string& );
		void setExamMark(const string& );
		
		//Need to check validity outside of the class
		
		//writeToFile(_IO_FILE*) const/
	
		bool operator==(const record& ) const;
		bool operator<(const record& ) const;	

		bool isValidExamMark(const string& ) const;

	private:
		string StudentID;
		string CourseCode;
		string ExamMark;				
};

#endif /*_ENTRIES_H*/
