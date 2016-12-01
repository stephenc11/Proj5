#ifndef _ENTRIES_H
#define _ENTRIES_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>

using std::string;
using std::list;

class student{
	public:
		/*default constructor/destructor*/
		student();
		~student();
		
		//conversion constructor
		student(const string& _id,const string& _name,const string& _year,const string& _gender);
		student(const string& _key);
		student(const student& );

		string getStudentID() const;
		string getStudentName() const;
		string getYear() const;
		string getGender() const;
		string getKey() const; //Return Primary Key

		void setStudentID(const string& );
		void setStudentName(const string& );
		void setYear(const string& );
		void setGender(const string& );
	
		bool operator==(const student& ) const;//only check key
		bool operator<(const student& ) const;
		
		static bool isValidStudentID(const string& ) ;
		static bool isValidStudentName(const string& ) ;
		static bool isValidYear(const string& ) ;
		static bool isValidGender(const string& ) ;

		void reportStudent(_IO_FILE*) const;
		void writeToFile(_IO_FILE*) const;
		
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
		course(const string& _key);
		course(const course& );

		string getCourseCode() const;
		string getCourseName() const;
		string getCredit() const;
		string getKey() const; //Return Primary Key		

		void setCourseCode(const string& );
		void setCourseName(const string& );
		void setCredit(const string& );

		bool operator==(const course& ) const; //only check key
		bool operator<(const course& ) const;	
		
		static bool isValidCourseCode(const string& );
		static bool isValidCourseName(const string& );
		static bool isValidCredit(const string& );

		void reportCourse(_IO_FILE*) const;
		void writeToFile(_IO_FILE*) const;
		
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

		record(const string& , const string&, const string& );
		record(const string& _key1, const string& _key2);
		record(const record& );

		string getStudentID() const;
		string getCourseCode() const;
		string getExamMark() const;	

		void setStudentID(const string&  );
		void setCourseCode(const string& );
		void setExamMark(const string& );
		
		//Need to check validity outside of the class
		
		void writeToFile(_IO_FILE*) const;
		//void reportRecord(_IO_FILE* ) const; 

		bool operator==(const record& ) const;
		bool operator<(const record& ) const;	
		
		static bool isValidExamMark(const string& );

	private:
		string StudentID;
		string CourseCode;
		string ExamMark;				
};

class Index{
	public:
		Index();
		~Index();
		
		Index(list<record>::iterator ,string );
		Index(const Index& );

		string getKey() const;
		list<record>::iterator getItr() const;
		
		bool operator< (const Index& ) const; 	
		bool operator== (const Index& ) const;		
		void setKey(const string& );

		//void report(IO_FILE* ) const;

	protected:
		list<record>::iterator _rcd;
		string _key;
};

/*two derived class of Index*/
//They are established to represent two Index concepts

class stuIndex : public Index{
	public:
		stuIndex();
		~stuIndex();
		
		stuIndex(list<record>::iterator ,string );
		stuIndex(const stuIndex& );

		string getID() const;
		void report(_IO_FILE* ) const;
};

class crsIndex : public Index{
	public:
		crsIndex();
		~crsIndex();		
	
		crsIndex(list<record>::iterator ,string );
		crsIndex(const crsIndex& );

		string getCode() const;
		void report(_IO_FILE* ) const;
};

#endif /*_ENTRIES_H*/