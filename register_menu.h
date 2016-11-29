#include "register_entries.h"
#include "register_record_manager.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


struct Menu{
	void RunStuMenu();
	void RunCrsMenu(){};
	void RunRegMenu(){};
	void RunFileMenu(){};

	void InsertStuRcd();
	void ModifyStuRcd();
	void DeleteStuRcd();
	void QueryStuRcd(){};
	
	string AskforStuName();
	string AskforYear();
	string AskforGender();

	string AskforCrsName();
	string AskforCredit();

	//string AskforMark();

	recordManager RcdMng;
};

void Menu::RunStuMenu(){

	system("clear");

	cout<<"T Course Registration System  (Student Menu)"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<endl;
	cout<<"1. Insert Student Record"<<endl;
	cout<<"2. Modify Student Record"<<endl;
	cout<<"3. Delete Student Record"<<endl;
	cout<<"4. Query Student Record"<<endl;
	cout<<"5. Go back to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your choice (1-5): ";
	
	while(1){
	
	string choice;
	getline(cin,choice);
	int co1 = atoi(choice.c_str()); 

	switch(co1){
		case 1:
			InsertStuRcd();
			return;	
				
		case 2:
			ModifyStuRcd();
			return;
		
		case 3:
			DeleteStuRcd();
			return;

		/*
		case 4:
		*/

		case 5:			
			return;

		default:
			cout<<"Invalid input, re-enter again (1-5): ";
	}

	}	
};

void Menu::InsertStuRcd(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (RcdMng.canFindStudent(s)) 
			{
				cout<<"Student already exists"<<endl;
				cout<<endl;
			}

			else{
				const string id(s);
				cout<<"Enter the student name: ";
				const string name(AskforStuName());
				cout<<"Enter the student year [1-3]: ";
				const string year(AskforYear());
				cout<<"Enter the student gender [M,F]: ";
				const string gender(AskforGender());
				student stu(id,name,year,gender);
				RcdMng.addStudent(stu);
				cout<<"Creation of student record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::ModifyStuRcd(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				cout<<"Enter the student name: ";
				const string name(AskforStuName());
				const string year(AskforYear());
				const string gender(AskforGender());
				student stu(id,name,year,gender);
				RcdMng.addStudent(stu);
				cout<<"Creation of student record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

void Menu::DeleteStuRcd(){

	cout<<"Enter the student ID: ";
	
	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentID(s)){

			if (!(RcdMng.canFindStudent(s))) 
			{
				cout<<"Student not exist"<<endl;
				cout<<endl;
			}
			else{
				const string id(s);
				RcdMng.deleteStudent(id);
				cout<<"Deletion of student record successful"<<endl;
				cout<<endl;
			}
			cout<<"Hit ENTER to continue..."<<endl;
			string s;
			getline(cin,s);
			return;	
		}
		else{
			cout<<"Invalid input, re-enter again [student ID]: ";
		}
	}
}

string Menu::AskforStuName(){
	

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidStudentName(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [student name]: ";
		}
	}
}

string Menu::AskforYear(){
	

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidYear(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [student year]: ";
		}
	}
}

string Menu::AskforGender(){
	

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(student::isValidGender(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [M,F]: ";
		}
	}
}

string Menu::AskforCrsName(){
	cout<<"Enter the course name: ";

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCourseName(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [course name]: ";
		}
	}
}

string Menu::AskforCredit(){
	cout<<"Enter the course credit [0-5]: ";

	while(1){
		string s;
		getline(cin,s);
	
		//check whether valid
		if(course::isValidCredit(s)){
			return s; 	
		}
		else{
			cout<<"Invalid input, re-enter again [course credit]: ";
		}
	}
}