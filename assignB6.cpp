/*
NAME : bhise viraj sharad
Roll no:84
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct CSLL
{
    int roll;
    struct CSLL *next;
};
typedef struct CSLL csll;
class mySet
{
   private:
          csll *head;
   public:
         mySet();
         void accept_set();
         void insert_at_end(csll *node);
         void display_set();
         int find_length_set();
         int search(int X);
         friend mySet find_intersection(mySet A,mySet B);
         friend mySet find_difference(mySet A,mySet B);
         friend mySet find_union(mySet A,mySet B);

};
mySet :: mySet()
{
   head=NULL;
}
void mySet :: insert_at_end(csll *node)
{
       csll *last;
       if(head==NULL)
       head=node;
       else
       {
         last=head;
         while(last->next !=head)
        last=last->next;
        last->next=node;
        node->next=head;
       }
}
void mySet :: accept_set()
{
int i,n;
csll *last,*node;
cout<<"\nEnter the total no. of student in the set:";
cin>>n;
for(i=0;i<n;i++)
{
node=new csll;
cout<<"\nEnter the roll number of student "<<i+1<<" :";
cin>>node->roll;
node->next=node;
if(i==0)
{
head=node;
last=node;
}
else
{
      last->next=node;
      node->next=head;
      last=node;
}
}
}
void mySet :: display_set()
{
   csll *temp;
   if(head == NULL)
   {
    cout<<"={}";
    cout<<"\nEmpty Set";
   }
   else
   {
    cout<<"={";
    temp=head;
    do
    {
    cout<<temp->roll<<",";
    temp=temp->next;
    }while(temp != head);
    cout<<"\b\b}";
   }
}
int mySet :: find_length_set()
{
     csll *temp;
     int count = 0;
     if(head == NULL)
     return 0;
     else
     {
      temp = head;
      do
      {
          count++;
          temp=temp->next;
       }while(temp != head);
       return count;
      }
}
int mySet :: search(int X)
{
      csll *temp;
      temp=head;
      do
      {
      if(temp->roll == X)
             return(1);
      temp=temp->next;
      }while(temp != head);
       return (0);
}
mySet find_intersection(mySet A,mySet B)
{
     int flag;
     mySet C;
     csll *node,*temp;
     temp=A.head;
     do
     {
      flag = B.search(temp->roll);
      if(flag==1)
      {
          node = new csll;
          node->roll=temp->roll;
          node->next=node;
          C.insert_at_end(node);
      }
      temp=temp->next;
      }while(temp != A.head);
      return C;
}
mySet find_difference(mySet A,mySet B)
{
     int flag;
     mySet C;
     csll *node,*temp;
     temp=A.head;
     do
     {
      flag = B.search(temp->roll);
      if(flag==0)
      {
          node = new csll;
          node->roll=temp->roll;
          node->next=node;
          C.insert_at_end(node);
      }
      temp=temp->next;
      }while(temp != A.head);
      return C;
}
mySet find_union(mySet A,mySet B)
{
     int flag;
     mySet C;
     csll *node,*temp;
     temp=A.head;
     do
     {
          node = new csll;
          node->roll=temp->roll;
          node->next=node;
          C.insert_at_end(node);
     temp=temp->next;
     }while(temp != A.head);
     temp = B.head;
     do
     {
      flag = A.search(temp->roll);
      if(flag==0)
      {
        node = new csll;
          node->roll=temp->roll;
          node->next=node;
          C.insert_at_end(node);
       }
      temp=temp->next;
      }while(temp != B.head);
      return C;
}
int main()
{
   int ch;
   mySet A,B,C;
   int m;
   system("clear");
   cout<<"\nEnter the total no student in the class :";
   cin>>m;
   do
   {
    cout<<"\n\t\t1 : Accept Set";
    cout<<"\n\t\t2 : Display Set";
    cout<<"\n\t\t3 : Students who like Vanilla or butterscotch or both";
    cout<<"\n\t\t4 : Students who like both Vanilla and butterscotch";
    cout<<"\n\t\t5 : Students who like only Vanilla not butterscotch";
    cout<<"\n\t\t6 : Students who like only butterscotch not Vanilla";
    cout<<"\n\t\t7 : No. of students who like neither Vanilla nor butterscotch";
    cout<<"\n\t\t8 : Exit";
    cout<<"\n\nEnter ur choice :";
    cin>>ch;
    switch(ch)
    {
     case 1 : cout<<"\nInput set A (Students who like Vanilla Ice-cream)";
              A.accept_set();
              cout<<"\nInput set B (Students who like butterscotch Ice-cream)";
              B.accept_set();
              break;
     case 2 : cout<<"\nset A (Students who like Vanilla )";
              A.display_set();
              cout<<"\nset B (Students who like butterscotch)";
              B.display_set();
              break;
     case 3 : cout<<"\nset A (Students who like Vanilla )";
              A.display_set();
              cout<<"\nset B (Students who like butterscotch)";
              B.display_set();
              C = find_union(A,B);
              cout<<"\n\nSet A U B (Students who like either or both)";
              C.display_set();
              break;
     case 4 : cout<<"\nset A (Students who like Vanilla )";
              A.display_set();
              cout<<"\nset B (Students who like butterscotch)";
              B.display_set();
              C = find_intersection(A,B);
              cout<<"\n\nSet A ^ B (Students who like both)";
              C.display_set();
              break;
     case 5 : cout<<"\nset A (Students who like Vanilla )";
              A.display_set();
              cout<<"\nset B (Students who like butterscotch)";
              B.display_set();
              C = find_difference(A,B);
              cout<<"\n\nSet A - B (Students who like only Vanilla)";
              C.display_set();
              break;
     case 6 : cout<<"\nset A (Students who like Vanilla )";
              A.display_set();
              cout<<"\nset B (Students who like butterscotch)";
              B.display_set();
              C = find_difference(B,A);
              cout<<"\n\nSet B-A (Students who like only butterscotch)";
              C.display_set();
              break;
     case 7 : cout<<"\nset A (Students who like Vanilla )";
              A.display_set();
              cout<<"\nset B (Students who like butterscotch)";
              B.display_set();
              C = find_union(A,B);
              cout<<"\n\nSet A U B (Students who like either or both)";
              C.display_set();
              cout<<"\nNo.of students who like neither Vanilla nor butterscotch = "<<m - C.find_length_set();
              break;
     case 8 : cout<<"\n Enter of program";
              break;
     default: cout<<"\nWrong choice entered !!! Plz try again";
     }
  }while(ch != 8);
  return 0;
} 
/****************output******************** 
dslab@ubuntu:~$ cd coder
dslab@ubuntu:~/coder$ g++ string1.cpp
dslab@ubuntu:~/coder$ ./a.out
Enter the total no student in the class :5

		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit

Enter ur choice :1

Input set A (Students who like Vanilla Ice-cream)
Enter the total no. of student in the set:5

Enter the roll number of student 1 :1

Enter the roll number of student 2 :2

Enter the roll number of student 3 :3

Enter the roll number of student 4 :4

Enter the roll number of student 5 :5

Input set B (Students who like butterscotch Ice-cream)
Enter the total no. of student in the set:3

Enter the roll number of student 1 :2

Enter the roll number of student 2 :5

Enter the roll number of student 3 :3

		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit

Enter ur choice :2

set A (Students who like Vanilla )={1,2,3,4,},
set B (Students who like butterscotch)={2,5,},
		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit

Enter ur choice :3

set A (Students who like Vanilla )={1,2,3,4,},
set B (Students who like butterscotch)={2,5,},

Set A U B (Students who like either or both)={1,2,3,4,},
		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit

Enter ur choice :5

set A (Students who like Vanilla )={1,2,3,4,},
set B (Students who like butterscotch)={2,5,},

Set A - B (Students who like only Vanilla)={1,},
		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit

Enter ur choice :6

set A (Students who like Vanilla )={1,2,3,4,},
set B (Students who like butterscotch)={2,5,},

Set B-A (Students who like only butterscotch)={}
Empty Set
		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit

Enter ur choice :7

set A (Students who like Vanilla )={1,2,3,4,},
set B (Students who like butterscotch)={2,5,},

Set A U B (Students who like either or both)={1,2,3,4,},
No.of students who like neither Vanilla nor butterscotch = 0
		1 : Accept Set
		2 : Display Set
		3 : Students who like Vanilla or butterscotch or both
		4 : Students who like both Vanilla and butterscotch
		5 : Students who like only Vanilla not butterscotch
		6 : Students who like only butterscotch not Vanilla
		7 : No. of students who like neither Vanilla nor butterscotch
		8 : Exit
*/
 
   





