/*
NAME : Bhise Viraj Sharad
Roll no:84
*/
#include<iostream>
using namespace std;
class Test
{
  int dsa[30],i,j,n,sum,cnt[50],k,rn[30];
  float av;
public:
   Test()
   {
      i=j=n=0;
      av=sum=k=0;
   }
   void getdata();
   void show();
   void avg();
   void Ab_stud();
   void HS_LS();
   void MS_score();
};
void Test::getdata()
{
   cout<<"\nHow many student in SE comp div:A";
   cin>>n;
   cout<<"\n\t---------------------------------";
   cout<<"\n\tEnter the marks scored for first test of subject DSA:";
   cout<<"\n\t-----------------------------------------------------";
   cout<<"\n\nStudent who remains Absent for the test please enter -1 for them:";
   cout<<"\n---------------------------------------------------------";
   for(i=0;i<n;i++)
   {
    cout<<"\nEnter the total marks of Roll no:"<<i+1<<" : ";
    cin>>dsa[i];
   }
}
void Test:: MS_score()
{
   for(i=0;i<50;i++)
   {
       cnt[i]=0;
   }
   for(i=0;i<50;i++)
   {
      for(j=0;j<n;j++)
      {
         if(dsa[j]==i)
         {
             cnt[i]=cnt[i]+1;
         }
       }
    }
    cout<<"\n\n Marks Scored by most of the student in the test are:\n";
    k=0;
    j=0;
        int max=cnt[j];
        for(i=0;i<50;i++)
        {
          if(cnt[i]>=max)
          {
               max=cnt[i];
               k=i;
           }
        }
        cout<<"\n\nMaximum marks "<<k<<" scored by "<<max<<" Students...\n";
        for(i=0;i<n;i++)
        {
           if(dsa[i]==k)
           {
               rn[j]=i;
               j++;
            }
         }
         cout<<"\n\n Students Roll Number are as follows..\n\n";
          for(i=0;i<j;i++)
          {
               cout<<"\t"<<rn[i]+1;
          }
}
void Test::show()
{
    cout<<"\n\nFirst Test Marks of Subject DSA are as follows..\n";
    cout<<"\n*****************************************************\n";
    cout<<"|     Roll No\t"<<"  |   "<<" DSA Marks       |";
    cout<<"\n*****************************************************\n";
    for(i=0;i<n;i++)
    {
       cout<<"|\t"<<i+1<<"\t|\t"<<dsa[i]<<"\t|\n";
    }
    cout<<"---------------------------------------------\n";
}
void Test :: avg()
{
    int p=0;
    cout<<"\nAverage Score of Class => ";
    for(i=0;i<n;i++)
    {
       if(dsa[i]!=-1)
       {
          sum=sum+dsa[i];
          p++;
        }
    }
    av=sum/p;
    cout<<av;
}
void Test :: Ab_stud()
{
   int cnt=0;
   cout<<"\n\nTotal Number of Student Absent for DSA Test\n";
   cout<<"\nRoll No\t Marks\n";
    for(i=0;i<n;i++)
    {
       if(dsa[i]==-1)
       {
         cout<<i+1<<"\tAbsent\n";
         cnt++;
        }
     }
     cout<<"\n\tTotal_Absent_Student :=: "<<cnt;
}
void Test :: HS_LS()
{
   int min=0;
   int max=0,rno=0,i=0;
   cout<<"\n\nHighest Score of the Class for DSA Subject are as follows..\n";
   max=dsa[i];
   for(i=0;i<n;i++)
   {
     if(dsa[i]==-1)
     {
     cout<<i+1<<"\tAbsent\n";
     }
     else if(dsa[i]>=max)
     {
        max=dsa[i];
        rno=i;
      }
    }
    cout<<"\n\tDSA Highest Score: "<<"Roll No : "<<rno+1<<" Marks : "<<max;
    cout<<"\n\nLowest Score of the Class for DSA Subject are as follows..\n";
    rno=0;
    min=dsa[j];
    for(j=0;j<n;j++)
    {
        if(dsa[j]==-1)
        {
         //cout<<j+1<<"\tAbsent\n";
        }
        else if(dsa[j]<=min)
        {
          min=dsa[j];
          rno=j;
         }
     }
     cout<<"\n\tDSA Lowest Score: "<<"Roll No : "<<rno+1<<" Marks : "<<min;
}
int main()
{
   Test T;
   T.getdata();
   T.show();
   T.avg();
   T.Ab_stud();
   T.HS_LS();
   T.MS_score();
   cout << "\n\n\n!!!Good Bye!!!" << endl;
   return 0;
}
/**************************output*********************************
dslab@ubuntu:~$ cd coder
dslab@ubuntu:~/coder$ g++ assignA2.cpp
dslab@ubuntu:~/coder$ ./a.out

How many student in SE comp div:A10

	---------------------------------
	Enter the marks scored for first test of subject DSA:
	-----------------------------------------------------

Student who remains Absent for the test please enter -1 for them:
---------------------------------------------------------
Enter the total marks of Roll no:1 : 98

Enter the total marks of Roll no:2 : 56

Enter the total marks of Roll no:3 : 75

Enter the total marks of Roll no:4 : 48

Enter the total marks of Roll no:5 : 95

Enter the total marks of Roll no:6 : 76

Enter the total marks of Roll no:7 : 65

Enter the total marks of Roll no:8 : 84

Enter the total marks of Roll no:9 : 54

Enter the total marks of Roll no:10 : 72


First Test Marks of Subject DSA are as follows..

*****************************************************
|     Roll No	  |    DSA Marks       |
*****************************************************
|	1	|	98	|
|	2	|	56	|
|	3	|	75	|
|	4	|	48	|
|	5	|	95	|
|	6	|	76	|
|	7	|	65	|
|	8	|	84	|
|	9	|	54	|
|	10	|	72	|
---------------------------------------------

Average Score of Class => 72

Total Number of Student Absent for DSA Test

Roll No	 Marks

	Total_Absent_Student :=: 0

Highest Score of the Class for DSA Subject are as follows..

	DSA Highest Score: Roll No : 1 Marks : 98

Lowest Score of the Class for DSA Subject are as follows..

	DSA Lowest Score: Roll No : 4 Marks : 48

 Marks Scored by most of the student in the test are:


Maximum marks 48 scored by 1 Students...


 Students Roll Number are as follows..

	4


!!!Good Bye!!!
******/



