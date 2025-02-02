#include"student.h"
student::student(string ne,string d,double c,double e,double m)
{
	name=ne,id=d;
	math=m,eng=e,chinese=c;
}
void student::showInfo()
{
	cout<<"学号："<<id<<"，姓名："<<name<<"，成绩：["<<"数学："<<math<<"，语文："<<chinese<<"，英语："<<eng<<"]\n";
}

