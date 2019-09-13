/*
NAME : bhise viraj sharad
Roll no:84
*/
#include<iostream>
using namespace std;
class binary;
class node
{
node *prev;
bool n;
node *next;
public:
node()
{

prev=next=NULL;
}
node(bool b)
{
n=b;
prev=next=NULL;
}
friend class binary;
};
class binary
{
node *start;
public:
binary()
{
start=NULL;
}
void generateBinary(int no);
void displayBinary();
void onesComplement();
void twosComplement();
binary operator +(binary n1);
bool addBitAtBegin(bool val)
{
node *nodee=new node(val);
if(start==NULL)
{
start=nodee;
}
else
{
nodee->next=start;
start->prev=nodee;
start=nodee;
}
return true;
}
};
void binary::generateBinary(int no)
{
bool rem;
node *p;
rem=no%2;
start=new node(rem);
no=no/2;
while(no!=0)
{
rem=no%2;
no=no/2;
p=new node(rem);
p->next=start;
start->prev=p;
start=p;
}
}
void binary::displayBinary()
{
node *t;
t=start;
while(t!=NULL)
{
cout<<t->n;
t=t->next;
}
}
void binary::onesComplement()
{
node *t;
t=start;
while(t!=NULL)
{
if(t->n==0)
t->n=1;
else
t->n=0;
t=t->next;
}
}
binary binary::operator +(binary n1)
{
binary sum;
node *a=start; 
node *b=n1.start;
bool carry=false;
while(a->next!=NULL)
a=a->next;
while(b->next!=NULL)
b=b->next;
while(a!=NULL && b!=NULL)
{
sum.addBitAtBegin((a->n)^(b->n)^carry);
carry=((a->n&& b->n) || (a->n&& carry) || (b->n && carry));
a=a->prev;
b=b->prev;
}
while(a!=NULL)
{
sum.addBitAtBegin(a->n^carry);
a=a->prev;
}
while(b!=NULL)
{
sum.addBitAtBegin(b->n^carry);
b=b->prev;
}
sum.addBitAtBegin(carry);
return sum;
}
void binary::twosComplement()
{
onesComplement();
bool carry=1;
node *t;
t=start;
while(t->next!=NULL)
{
t=t->next;
}
while(t!=NULL)
{
if(t->n==1 && carry==1)
{
t->n=0;
carry=1;
}
else
if(t->n==0 && carry==1)
{
t->n=1;
carry=0;
}
else
if(carry==0)
break;
t=t->prev;
}
displayBinary();
}
int main()
{
int num,num1;
binary n1,n3,n2;
int choice=1;
do
{
cout<<"\n\n ===========Binary no operation===========\n";
cout<<"1. Generate binary\n2. one's complement\n3.two's complements\n4.Addition\n5.exit\n enter your choice: ";
cin>>choice;
switch(choice)
{
case 1:cout<<"enter no in decimal form:";
cin>>num;
n1.generateBinary(num);
cout<<"\n Binary representation:";
n1.displayBinary();
break;
case 2:
cout<<"enter no in decimal form:";
cin>>num;
n1.generateBinary(num);
cout<<"\n Binary representation:";
n1.displayBinary();
cout<<"ones complement";
n1.onesComplement();
n1.displayBinary();
break;
case 3:
cout<<"enter no in decimal form:";
cin>>num;
n1.generateBinary(num);
cout<<"\n Binary representation:";
n1.displayBinary();
cout<<"twos complement";
n1.twosComplement();
n1.displayBinary();
break;
case 4:
cout<<"enter two no: ";
cin>>num>>num1;
n1.generateBinary(num);
n2.generateBinary(num1);
n1.displayBinary();
cout<<"= ";
n3=n1+n2;
n3.displayBinary();
case 5:
cout<<"end of program";
break;
default:cout<<"\n wrong choice!! try again!!! ";
}}while(choice!=5);
return 0;
}
/**********************output****************************
dslab@ubuntu:~$ cd coder
dslab@ubuntu:~/coder$ g++ assignB7.cpp
dslab@ubuntu:~/coder$ ./a.out


 ===========Binary no o[peration===========
1. Generate binary
2. one's complement
3.two's complements
4.Addition
5.exit
 enter your choice: 1
enter no in decimal form:3

 Binary representation:11

 ===========Binary no o[peration===========
1. Generate binary
2. one's complement
3.two's complements
4.Addition
5.exit
 enter your choice: 2
enter no in decimal form:4

 Binary representation:100ones complement011

 ===========Binary no operation===========
1. Generate binary
2. one's complement
3.two's complements
4.Addition
5.exit
 enter your choice: 3
enter no in decimal form:2

 Binary representation:10twos complement1010

 ===========Binary no operation===========
1. Generate binary
2. one's complement
3.two's complements
4.Addition
5.exit
 enter your choice: 4
enter two no: 4
5
100= 1001end of program

 ===========Binary no operation===========
1. Generate binary
2. one's complement
3.two's complements
4.Addition
5.exit
 enter your choice: 5
end of program
*****/
