/*
 * Problem Statement :- Write a program non-recursive and recursive program to calculate
 *                      Fibonacci numbers and analyze their time and space complexity.
 * Recursive
 * Time Complexity  : O(2^n)
 * Space Complexity : O(n)

 * Non-Recursive
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

#include <bits/stdc++.h>

using namespace std;

int recursiveFibonacci(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return recursiveFibonacci(n-1)+recursiveFibonacci(n-2);
}

int iterativeFibonacci(int n)
{
	int a=0;
	int b=1;
	int c;
	if(n==0) return 0;
	if(n==1) return 1;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main()
{
	int ch,n;
	while(1)
	{
		cout<<"\nEnter your choice: \n1.Recursive Fibonacci\n2.Iterative Fibonacci\n3.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the n to find nth fibonacci number"<<endl;
				cin>>n;
				cout<<n<<"th Fibonacci Number is "<<recursiveFibonacci(n)<<endl;
				break;
			}	
			case 2:
			{
				cout<<"Enter the n to find nth fibonacci number"<<endl;
				cin>>n;
				cout<<n<<"th Fibonacci Number is "<<iterativeFibonacci(n)<<endl;
				break;
			}
			case 3:
			{
				cout<<"Terminated"<<endl;
				return 0;
				break;
			}
			default:
			{
				cout<<"Please enter valid choice\n";
				break;
			}
		}		
	}
	return 0;
}