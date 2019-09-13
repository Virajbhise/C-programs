/*
NAME : bhise viraj sharad
Roll no:84
*/
#include<iostream>
using namespace std;
class matrix
{
private:
	int a[5][5],b[5][5],c[5][5],m,n;
public:
	void getB();
	void add();
	void transpose();
	void sub();
	void triangular();
	void diagSum();
	void getA();
	void multiply();
	void order()
	{
		cout<<"\nEnter number of rows and columns";
		cin>>m>>n;
	}
	void saddlePoint();
};
void matrix::getA()
{
	order();
	cout<<"Enter  matrix: ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
}
void matrix::diagSum()
{
	int u=0,v;//for diagonal location
	int x=0,y=0;

	v=n-1;
	if(m==n)
	{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				x=x+a[i][j];
				y=y+a[u][v];
			}
		}
		u++;
		v--;
	}
	cout<<"\nsum X="<<x<<"\nSUM OF Y = "<<y<<"\n";
	}
	else
	{
		cout<<"Order not same";
		return;
	}
}
void matrix::triangular()
{

int flag1=1,flag2=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<=j)
			{
			if(a[i][j]!=0)
			{
				flag1=1;
			}
			else
			{
				flag1=0;
				goto X;
				//cout<<"This is not Upper Triangular";
				//return;
			}
		}
		if(i>j)
		{
			if(a[i][j]==0)
				flag2=1;
				else
					flag2=0;
		}
		n--;
	}
	}
	if(flag1==flag2==1)
	cout<<"\nThis is Upper Triangular matrix\n";
	else
		X:cout<<"\nThis is not upper triangular matrix\n";
}



void matrix::getB()
{

		 cout<<"Enter Second  matrix: ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>b[i][j];
		}
	}
}

void matrix::add()
{getB();



cout<<"Addition is \n";
for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		c[i][j]=a[i][j]+b[i][j];
		cout<<" "<<c[i][j]<<" ";
	}
	cout<<"\n";
}


}

void matrix::sub()
{getB();


	cout<<"Subtraction is \n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
			cout<<" "<<c[i][j]<<" ";
		}
		cout<<"\n";
	}

}

void matrix::transpose()
{
	int tmp[5][5];

	cout<<"\nOriginal Matrix:\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<a[i][j];
		}
	cout<<"\n";
	}
	cout<<"Transpose of Matrix A is:: \n";
	for(int i=0;i<m;i++)
	{

		for(int j=0;j<n;j++)
		{
			tmp[i][j]=a[j][i];
			cout<<" "<<tmp[i][j]<<" ";
		}
		cout<<"\n";
	}

}

void matrix::multiply()
{
getB();

for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		c[i][j]=0;
		for(int k=0;k<n;k++)
		{
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
		cout<<" "<<c[i][j];
	}
}
}

void matrix::saddlePoint(){
	int pos[2][2],min,max;
	int i,j,k;
	for(i=0;i<n;i++){
		min=a[i][0];
		for(j=0;j<n;j++){
			if(min>=a[i][j])
			{
				min=a[i][j];
				pos[0][0]=i;
				pos[0][1]=j;
			}
		}
		j=pos[0][1];
		max=a[0][j];
		for(k=0;k<n;k++)
		{
			if(max<=a[k][j])
			{
				max=a[i][j];
				pos[1][0]=k;
				pos[1][1]=j;
			}
		}
		//min of row and max of column
		if(min==max)
		{
			if(pos[0][0]==pos[1][0] && pos[0][1]==pos[1][1])
				cout<<"\nSaddle point at ( "<<pos[0][0]<<","<<pos[0][1]<<") = "<<max<<endl;;
		}
	}
}
int main()
{
	void line();
	cout<<"=============Matrix Operations=================\n";
	int choice;
	matrix mat;
	mat.getA();

	do
	{
		line();
		cout<<"\n1. Addition of two matrix"
				<<"\n2. Transpose of matrix"
				<<"\n3. Subtraction of two matrices"
				<<"\n4. Check  If Triangular"
				<<"\n5. Reenter Matrix A."
				<<"\n6.Sum of Diagonal elements."
				<<"\n7.Multiplication of matrix;"
				<<"\n8. Saddle point"
				<<"\nEnter 0 to exit"
				<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{

		case 1:line();
		mat.add();
		break;
		case 2:
			line();
			mat.transpose();
			break;
		case 3:
			mat.sub();
			break;
		case 4:
			mat.triangular();
			break;\
		case 5:
			mat.getA();
			break;
		case 6:
			mat.diagSum();
			break;
		case 7: mat.multiply();
		break;
		case 8: mat.saddlePoint();
		break;
		default:
			line();
			cout<<"\nGOOD BYE:"
					;
			line();
		}
	}
	while(choice!=0);
	//mat.getdata();
	//mat.add();
	//mat.transpose();
	return 0;
}
void line()
{
	cout<<"\n=================================================\n";
}
/*****************output*****************
dslab@ubuntu:~$ cd coder
dslab@ubuntu:~/coder$ g++ assignA3.cpp
dslab@ubuntu:~/coder$ ./a.out
=============Matrix Operations=================

Enter number of rows and columns3 3
Enter  matrix: 1 2 3
               2 3 4
               3 4 5

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 1

=================================================
Enter Second  matrix: 2 3 5
                      4 5 6
                      3 6 8
Addition is 
 3  5  8 
 6  8  10 
 6  10  13 

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 2

=================================================

Original Matrix:
 1 2 3
 2 3 4
 3 4 5
Transpose of Matrix A is:: 
 1  2  3 
 2  3  4 
 3  4  5 

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 3
Enter Second  matrix: 1 2 3
                      2 3 5
                      0 0 0
Subtraction is 
 0  0  0 
 0  0  -1 
 3  4  5 

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 4

This is not upper triangular matrix

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 5

Enter number of rows and columns3 3
Enter  matrix: 3 4 5 
               2 1 0 
               6 5 1

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 6

sum X=5
SUM OF Y = 12

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 7
Enter Second  matrix: 3 4 5 
                      0 1 1 
                      1 2 3
 14 26 34 6 9 11 19 31 38
=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 8

Saddle point at ( 2,2) = 1

=================================================

1. Addition of two matrix
2. Transpose of matrix
3. Subtraction of two matrices
4. Check  If Triangular
5. Reenter Matrix A.
6.Sum of Diagonal elements.
7.Multiplication of matrix;
8. Saddle point
Enter 0 to exit
Enter your choice : 0

=================================================

GOOD BYE:
================================================
*/

