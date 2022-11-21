/*
 * Problem Statement :- Write a program for analysis of quick sort by using deterministic
 * 						and randomized variant.
 */

// #include<bits/stdc++.h>
// using namespace std;

// //Deterministic Quick-sort
// // Pivot => last element in the array

// int partition(vector<int> &a, int l, int h)
// {
// 	int index = l;
// 	int pivot = h;
// 	for(int i=l; i<h; i++)
// 	{
// 		if(a[i] < a[pivot])
// 		{
// 			swap(a[i], a[index]);
// 			index++;
// 		}
// 	}
// 	swap(a[pivot], a[index]);
// 	return index;
// }

// int r_partition(vector<int> &a, int l, int h)
// {
// 	int num = rand();
// 	int ri = l + num%(h-l+1);
// 	swap(a[h], a[ri]);
// 	return partition(a, l, h);
// }

// void quickSort(vector<int> &a, int low, int high)
// {
// 	if(low >= high) return;

// 	int pi = partition(a, low, high);
// 	quickSort(a, low, pi-1);
// 	quickSort(a, pi+1, high);
// }

// void r_quickSort(vector<int> &a, int low, int high)
// {
// 	if(low >= high) return;

// 	int pi = r_partition(a, low, high);
// 	r_quickSort(a, low, pi-1);
// 	r_quickSort(a, pi+1, high);
// }

// int main()
// {
// 	int choice, n;
// 	while(true)
// 	{
// 		cout<<"\n\n Main-Menu \n\t 1. Deterministic Quick-Sort \n\t 2. Randomized Quick-Sort \n\t 3. Exit "<<endl;
// 		cout<<"\n\t Enter choice: ";
// 		cin>>choice;

// 		if(choice == 1)
// 		{
// 			cout<<"\n\t Enter the number of data element to be sorted: ";
// 			cin>>n;
// 			vector<int> a(n);

// 			cout<<"\n\t Enter the array: ";
// 			for(int i=0; i<n; i++) cin>>a[i];

// 			quickSort(a, 0, n-1);

// 			cout<<"\n\t Sorted Data: ";
// 			for (int i=0; i<n; i++) cout<<a[i]<<" ";
// 		}
// 		else if(choice == 2)
// 		{
// 			cout<<"\n\t Enter the number of data element to be sorted: ";
// 			cin>>n;
// 			vector<int> a(n);

// 			cout<<"\n\t Enter the array: ";
// 			for(int i=0; i<n; i++) cin>>a[i];

// 			r_quickSort(a, 0, n-1);

// 			cout<<"\n\t Sorted Data: ";
// 			for (int i=0; i<n; i++) cout<<a[i]<<" ";
// 		}
// 		else if(choice == 3)
// 		{
// 			cout<<"\n\t Thank you!!!";
// 			exit(0);
// 		}
// 		else
// 		{
// 			cout<<"\n\t Enter valid choice"<<endl;
// 		}
// 	}
// }


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