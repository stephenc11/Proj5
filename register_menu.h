//#include "register_record_manager.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct Menu{
	void RunStuMenu();
	void RunCrsMenu(){};
	void RunRegMenu(){};
	void RunFileMenu(){};

	void InsertStuRcd();
	void ModifyStuRcd(){};
	void DeleteStuRcd(){};
	void QueryStuRcd(){};
		
	//recordManager RcdMng;
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

			break;
		
		/*			
		case 2:
			
		case 3:

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
		//if(isValid(s)){

		//}
		
		if (1) {
			cout<<"Student already exists"<<endl;
			cout<<endl;
			cout<<"Hit ENTER to continue..."<<endl;
		}
		//check whether exist
	
		break;
	}
};


