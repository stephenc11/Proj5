#ifndef _ENTRIES_H
#define _ENTRIES_H

#include <string>

using std::string;

class student{
	public:
		/*default constructor/destructor*/
		student();
		~student();
	    
		//Student::Student(_IO_FILE*)
		
		student(string& ,string&, string& ,string& );
	
		//student::writeToFile(_IO_FILE*) const
		
		int getStudentID() const;
		string getStudentName() const;
		int getYear() const;
		char getGender() const;

		void setStudentID(int );
		void setStudentName(string );
		void setYear(int );
		void setGender(char );
	
		bool isValidStudentID(int ) const;
		bool isValidStudentName(string ) const;
		bool isValidYear(int ) const;
		bool isValidGender(char ) const;

		bool operator==(const student& ) const;//only check key
		bool operator<(const student& ) const;

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


class record{
	public:
		/*default constructor/destructor*/
		record();
		~record();

		int getStudentID() const;
		string getCourseCode() const;
		int getExamMark() const;

		void setStudentID(int );
		void setCourseCode(string );
		void setExamMark(int );
		
		
		bool isValidExamMark() const;
		 

		//Need to check validity outside of the class
		
		//writeToFile(_IO_FILE*) const/
	
		bool operator==(const record& ) const;
		bool operator<(const record& ) const;	

	private:
		int StudentID;
		string CourseCode;
		int ExamMark;				
};

#endif /*_ENTRIES_H*/
