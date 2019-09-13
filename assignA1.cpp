/*
NAME :Bhise Viraj Sharad
Roll no:84
*/
#include<iostream>
using namespace std;

class Student
{
	int sid[50];
	int total;
	public:
		Student()
		{
			total=0;
		}
		void accept();
		void display();
		void intersection(Student,Student);
		int unionS(Student,Student);
		void diff(Student,Student);
};

void Student::accept()
{
	cout<<"\nENter Number of Students: ";
	cin>>total;
	for(int i=0;i<total;i++)
	{
		cout<<"Enter Student Id: ";
		cin>>sid[i];
		for(int j=0;j<i;j++)
		{
			if(sid[j]==sid[i])
			{
				cout<<"\nRepeated Record.Please Enter Again!!";
				i--;
				break;
			}
			}	
	}
}

void Student::display()
{
	for(int i=0;i<total;i++)
	{
		cout.width(5);
		cout<<sid[i];
	}
	cout<<endl;
}
void Student::intersection(Student s1,Student s2)
{
	for(int i=0;i<s1.total;i++)
	{
		for(int j=0;j<s2.total;j++)
		{
			if(s1.sid[i]==s2.sid[j])
			{
				sid[total]=s1.sid[i];
				total++;
				break;
			}
		}
	}
}
void Student::diff(Student s1,Student s2)
{
	int flag=1;
	for(int i=0;i<s1.total;i++)
	{
		for(int j=0;j<s2.total;j++)
		{
			if(s1.sid[i]==s2.sid[j])
			{
				flag=0;
				break;
			}
			else flag=1;
		}
		if(flag==1)
		{
			sid[total]=s1.sid[i];
			total++;
		}
	}
}
int Student::unionS(Student s1,Student s2)
{
	int flag=0;
	int i=0;
	for(i=0;i<s1.total;i++)
	{
		sid[total]=s1.sid[i];
		total++;
	}
	for(int j=0;j<s2.total;j++)
	{
		flag=0;
		for(i=0;i<s1.total;i++)
		{
			if(s1.sid[i]==s2.sid[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			sid[total]=s2.sid[j];
			total++;
		}
	}
	return total;
}

int main()
{
	Student cric,bad,sunion,onlycric,onlybad,both;
	int class_total,union_total;
	
	cout<<"\nENter Number of Students in a class : ";
	cin>>class_total;
	cout<<"\nEnter INFO FOR Students who play cricket: \n";
	cric.accept();
	cout<<"\nEnter INFO FOR Students who play Badminton: \n";
	bad.accept();
	cout<<"\n---------------------------------------------------\n";
	cout<<"|              Students' Information              |";
	cout<<"\n---------------------------------------------------\n";
	cout<<"Cricket Set :";
	cric.display();
	cout<<"\nBadminton Students Set: ";
	bad.display();
	cout<<"\nCricket or badminton or both Students set: ";
	union_total= sunion.unionS(cric,bad);
	sunion.display();
	cout<<"\nStudents play Both Cricket and Badminton Set: ";
	both.intersection(cric,bad);
	both.display();
	cout<<"\nStudents play only cricket set: ";
	onlycric.diff(cric,bad);
	onlycric.display();
	cout<<"\nStudents play only badminton set: ";
	onlybad.diff(bad,cric);
	onlybad.display();
	cout<<"\nTotal Number of students who play neither cricket nor badminton: "<<class_total-union_total;
	return 0;
}
/******************output*************************
dslab@ubuntu:~$ cd coder
dslab@ubuntu:~/coder$ g++ assignA1.cpp
dslab@ubuntu:~/coder$ ./a.out

ENter Number of Students in a class : 50

Enter INFO FOR Students who play cricket: 

ENter Number of Students: 10
Enter Student Id: 1
Enter Student Id: 2
Enter Student Id: 3
Enter Student Id: 4
Enter Student Id: 5
Enter Student Id: 6
Enter Student Id: 7
Enter Student Id: 8
Enter Student Id: 9
Enter Student Id: 10

Enter INFO FOR Students who play Badminton: 

ENter Number of Students: 5
Enter Student Id: 5
Enter Student Id: 4
Enter Student Id: 3
Enter Student Id: 2
Enter Student Id: 
1

---------------------------------------------------
|              Students' Information              |
---------------------------------------------------
Cricket Set :    1    2    3    4    5    6    7    8    9   10

Badminton Students Set:     5    4    3    2    1

Cricket or badminton or both Students set:     1    2    3    4    5    6    7    8    9   10

Students play Both Cricket and Badminton Set:     1    2    3    4    5

Students play only cricket set:     6    7    8    9   10

Students play only badminton set: 

Total Number of students who play neither cricket nor badminton: 40
*/
