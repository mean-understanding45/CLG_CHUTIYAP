/*
 * Problem Statement :- Write a program for analysis of quick sort by using deterministic
 * 						and randomized variant.
 */

#include <bits/stdc++.h>
using namespace std;

class Sorting{
	vector<int> arr;
public:
	Sorting()
	{
		cout<<"Enter the size of the array: ";
		int n,x;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			arr.push_back(x);
		}
	}

	int getArraySize()
	{
		return arr.size();
	}

	int partition(int l,int h)
	{
		int index=l;
		int pivot=h;
		for(int i=l;i<h;i++)
		{
			if(arr[i]<arr[pivot])
			{
				swap(arr[i],arr[index++]);
			}
		}
		swap(arr[index],arr[pivot]);
		return index;
	}

	void quickSort(int l,int h)
	{
		if(l>=h) return;
		int pi=partition(l,h);
		quickSort(l,pi-1);
		quickSort(pi+1,h);
	}

	int r_partition(int l,int h)
	{
		int num = rand();
		int ri = l + num%(h-l+1);
		swap(arr[h],arr[ri]);
		return partition(l,h);
	}


	void r_quickSort(int l,int h)
	{
		if(l>=h) return;
		int pi=r_partition(l,h);
		r_quickSort(l,pi-1);
		r_quickSort(pi+1,h);
	}

	void printArray()
	{
		for(auto x:arr) cout<<x<<" ";
		cout<<"\n";
	}

};

int main()
{
	Sorting s;
	cout<<"\nSorting by Quick Sort- ";
	s.quickSort(0,s.getArraySize()-1);
	s.printArray();
	cout<<"\nSorting by Randomized Quick Sort- ";
	s.r_quickSort(0,s.getArraySize()-1);
	s.printArray();
	return 0;
}