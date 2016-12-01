#ifndef _MENU_H
#define _MENU_H

#include "register_entries.h"
#include "register_record_manager.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Menu{

	//Sub Menus
	void RunStuMenu();
	void RunCrsMenu();
	void RunRegMenu();
	void RunRprtMenu();
	void RunFileMenu();

	//Student Menu Options
	void InsertStuRcd();
	void ModifyStuRcd();
	void DeleteStuRcd();
	void QueryStuRcd();
	
	//Course Menu Options
	void InsertCrsRcd();
	void ModifyCrsRcd();
	void DeleteCrsRcd();
	void QueryCrsRcd();
	
	//Registration Menu Options
	void AddCourse();
	void DropCourse();
	void ModifyExamMark();
	void QueryReg();

	/*Askfor Functions*/
	//Ask for input and check validity
	string AskforStuName();
	string AskforYear();
	string AskforGender();
	string AskforCrsName();
	string AskforCredit();
	string AskforMark();
	string AskforCrsCode();
	string AskforStuID();
	
	recordManager RcdMng;
};

#endif /*_MENU_H*/
