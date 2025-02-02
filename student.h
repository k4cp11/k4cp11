#pragma once
#include<string>
#include<iostream>
using namespace std;
class student
{
	
	public:
	string name,id;
	double chinese,eng,math;
	void showInfo();
	student(string name,string id,double c,double e,double m);
};
