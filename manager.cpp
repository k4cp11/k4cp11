#include"manager.h"
bool cmpById(student a,student b)
{
	return a.id<b.id;
}
bool cmpByScore(student a,student b)
{
	return (a.eng+a.math+a.chinese)>(b.eng+b.math+b.chinese);
}
void manager::load()
{
	ifstream ifs;
	ifs.open("studentInfo.txt",ios::in);
	string ii,nn;
	double cc,mm,ee;	
	while(ifs>>ii>>nn>>cc>>mm>>ee)
	{	
		if(ii=="\n")
		{
			break;
		}
		cls.push_back(student(nn,ii,cc,ee,mm));
	}
	ifs.close();
}
void manager::rd()
{
	ofstream ofs;
	ofs.open("studentInfo.txt",ios::out);
	for(int i=0;i<cls.size();i++)
	{
		ofs<<cls[i].id<<" "<<cls[i].name<<" "<<cls[i].chinese<<" "<<cls[i].math<<" "<<cls[i].eng<<endl;
	}
	ofs.close();
}
manager::manager()
{
	load();
//	cout<<cls.size()<<endl;
}
manager::~manager()
{
	rd();
	cls.clear();
}
int manager::findStudent(string id)
{
	for(int i=0;i<cls.size();i++)
	{
		if(cls[i].id==id)
		{
			return i;
		}
	}
	return -1;
}
void manager::modiStudent()
{
	cout<<"请输入要修改的学生的学号";
	string id;
	cin>>id;
	int pos=findStudent(id);
	if(pos==-1)
		cout<<"该学生不存在\n";
	else
	{
		while(1)
		{
			cout<<"请选择：\n";
			cout<<"1:修改学生姓名\n";
			cout<<"2:修改学生语文成绩\n";
			cout<<"3:修改学生数学成绩\n";
			cout<<"4.修改学生英语成绩\n";	
			cout<<"5.停止修改\n";
			int opt;
			cin>>opt;
			if(opt==1)
			{
				cout<<"请输入学生姓名：\n";
				string ne;
				cin>>ne;
				cls[pos].name=ne;
			}
			else if(opt==2)
			{
				cout<<"请输入学生语文成绩：\n";
				double c;
				cin>>c;
				cls[pos].chinese=c;
			}
			else if(opt==3)
			{
				cout<<"请输入学生数学成绩：\n";
				double m;
				cin>>m;
				cls[pos].math=m;
			}
			else if(opt==4)
			{
				cout<<"请输入学生英语成绩：\n";
				double e;
				cin>>e;
				cls[pos].eng=e;
			}
			else
			{
				system("pause");
				system("cls");
				return;
			}
			cout<<"修改成功！\n";
			system("pause");
			system("cls");		
		}
		

	}
	system("pause");
	system("cls");
	
}
int manager::findStudentByName(string ne)
{
	for(int i=0;i<cls.size();i++)
	{
		if(cls[i].name==ne)
			return i;
	}
	return -1;
}
void manager::showStudent()
{
	cout<<"请选择：\n";
	cout<<"1:根据学号查询\n";
	cout<<"2:根据姓名查询\n";	
	int opt;
	cin>>opt;
	if(opt==1)
	{	
		cout<<"请输入学生学号：\n";
		string id;
		cin>>id;
		int pos=findStudent(id);
		if(pos==-1)
		{
			cout<<"该学生不存在！\n";
		}
		else
		{
			cls[pos].showInfo();
		}
	}	
	else if(opt==2)
	{
		cout<<"请输入学生姓名：\n";
		string ne;
		cin>>ne;
		int pos=findStudentByName(ne);
		if(pos==-1)
		{
			cout<<"该学生不存在！\n";
		}
		else
		{
			cls[pos].showInfo();
		}
	}
	else
	{
		cout<<"输入无效！\n";
	}
		system("pause");
		system("cls");	
}
void manager::showMenu()
{
	while(1)
	{
		cout<<"**************************\n";
		cout<<"******1.添加学生信息******\n";
		cout<<"******2.修改学生信息******\n";	
		cout<<"******3.查询学生信息******\n";
		cout<<"******4.删除学生信息******\n";
		cout<<"******5.显示学生信息******\n";
		cout<<"******6.学生成绩统计******\n";
		cout<<"**********7.退出**********\n";
		cout<<"**************************\n";	
		int opt;
		cin>>opt;
		if(opt==1)
		{
			addStudent();
		}
		else if(opt==2)
		{
			modiStudent();
		}
		else if(opt==3)
		{
			showStudent();
		}
		else if(opt==4)
		{
			delStudent();
		}
		else if(opt==5)
		{
			showAllStudent();	
		}
		else if(opt==6)
		{
			statis();
		}
		else if(opt==7)
		{
			exit(0);
		}
		system("pause");
		system("cls");	
	 } 

}
void manager::addStudent()
{
	cout<<"请依次输入学生的学号，姓名，语文，数学，英语成绩\n";
	string id,ne;
	double cc,mm,ee;
	cin>>id>>ne>>cc>>mm>>ee;
	int pos=findStudent(id);
	if(pos!=-1)
	{
		cout<<"该学号已存在！\n";
		return;
	}	
	cls.push_back(student(ne,id,cc,ee,mm));
	cout<<"添加成功！\n";
	system("pause");
	system("cls");
}
void manager::delStudent()
{
	cout<<"请输入要删除的学生的学号："<<endl;
	string id;
	cin>>id;
	int pos=findStudent(id); 
	if(pos==-1)
	{
		cout<<"该学生不存在！"<<endl;
		return;
	}
	else
	{
		cls.erase(cls.begin()+pos);
		cout<<"删除成功！\n";
		return;
	}
}
void manager::showAllStudent()
{
	cout<<"请选择：\n";
	cout<<"1：按学号排序\n";
	cout<<"2：按成绩排序\n";
	int opt;
	cin>>opt;
	if(opt==1)
	{
		sort(cls.begin(),cls.end(),cmpById);
		for(int i=0;i<cls.size();i++)
			cls[i].showInfo();
	}
	else if(opt==2)
	{
		sort(cls.begin(),cls.end(),cmpByScore);
		for(int i=0;i<cls.size();i++)
			cls[i].showInfo();
	}
	else
	{
		cout<<"输入无效！\n";
	}
}
void manager::statis()
{
	if(cls.size()==0)
	{
		cout<<"本班暂无学生\n";
		return;
	}
	double ca=0,cmx=0,cmi=99999999,ma=0,mmx=0,mmi=9999999,ea=0,emx=0,emi=9999999,sa=0,smx=0,smi=99999999;
	for(int i=0;i<cls.size();i++)
	{
		cmx=max(cmx,cls[i].chinese),cmi=min(cmi,cls[i].chinese),ca+=cls[i].chinese/double(cls.size());
		mmx=max(mmx,cls[i].math),mmi=min(mmi,cls[i].math),ma+=cls[i].math/double(cls.size());
		emx=max(emx,cls[i].eng),emi=min(emi,cls[i].eng),ea+=cls[i].eng/double(cls.size());
		smx=max(smx,cls[i].chinese+cls[i].math+cls[i].eng),smi=min(smi,cls[i].chinese+cls[i].math+cls[i].eng),sa+=(cls[i].chinese+cls[i].math+cls[i].eng)/double(cls.size());
	}
	cout<<"语文平均分："<<ca<<"\t，语文最高分："<<cmx<<"\t，语文最低分："<<cmi<<'\n'; 
	cout<<"数学平均分："<<ma<<"\t，数学最高分："<<mmx<<"\t，数学最低分："<<mmi<<'\n'; 
	cout<<"英语平均分："<<ea<<"\t，英语最高分："<<emx<<"\t，英语最低分："<<emi<<'\n'; 
	cout<<"总分平均分："<<sa<<"\t，总分最高分："<<smx<<"\t，总分最低分："<<smi<<'\n'; 
}
