#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include "register_menu.h"
#include "register_record_manager.h"

using namespace std;

int main(){
	//bool quit = false;
	Menu m;
	while(1){

		system("clear");
		cout<<"HKUST Course Registration System"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<endl;
		
	 	cout<<"1. Student Management"<<endl;
		cout<<"2. Course Management"<<endl;
		cout<<"3. Course Registration"<<endl;
		cout<<"4. Report Management"<<endl;
		cout<<"5. File Management"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<endl;
		cout<<"Enter your choice (1-6): ";

		
		bool flag = false;

		while(!flag){

			string choice;
			getline(cin, choice);	
			
			int co = std::atoi(choice.c_str());
			
			/*if(choice.compare("6")==0)
				quit = true;*/

		switch(co){
			
			case 1:
			
				m.RunStuMenu();
				flag = true;

				break;				

			case 2:

				m.RunCrsMenu();
				flag = true;

				break;

			case 3:
				
				m.RunRegMenu();
				flag = true;
				
				break;	


			case 4:

				m.RunRprtMenu();
				flag = true;

				break;


			case 5:
				
				m.RunFileMenu();
				flag = true;

				break;

			case 6:
				return 0;

			default:
				cout<<"Invalid input, re-enter again (1-6): ";		
		}		

	}
		//quit = true;
	}

	return 0;
}