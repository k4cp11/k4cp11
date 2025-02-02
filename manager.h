#pragma once
#include"student.h"
#include<vector>
#include<fstream>
#include<algorithm>
class manager
{
	public:
	void showMenu();
	vector<student> cls;
	void load();
	void rd();
	manager();
	void addStudent();
	void modiStudent();
	void showAllStudent();
	int findStudent(string id);
	int findStudentByName(string ne); 
	void showStudent();
	void delStudent();
	void statis();
	~manager();	
};
