/*
 * Problem Statement :- Write a program to implement Huffman Encoding using a greedy
 * 						strategy.
 *
 * Time Complexity  : O(nlogn)   (n => number of unique characters in string)
 * Space Complexity : O(n)
 */

//aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff

#include <bits/stdc++.h>

using namespace std;

class Node{
	char data;
	int freq;
	Node* lchild;
	Node* rchild;
public:
	Node(char d,int f)
	{
		this->data=d;
		this->freq=f;
		lchild=NULL;
		rchild=NULL;
	}

	Node(Node* l,Node* r)
	{
		this->lchild=l;
		this->rchild=r;
		this->data=0;
		this->freq=l->freq+r->freq;
	}

	void traverse(string code="") const
	{
		if(this->lchild!=NULL)
		{
			this->lchild->traverse(code+'0');
			this->rchild->traverse(code+'1');
		}
		else
		{
			cout<<"\n\t"<<setw(10)<<this->data<<setw(10)<<this->freq<<setw(15)<<code<<"\n";
		}
	}
 	bool operator<(const Node& a) const
	{
		return this->freq>a.freq;
	}
};



void huffmanCoding(string str)
{
	priority_queue<Node> pq;
	vector<int> frequency(256,0);

	for(int i=0;i<str.size();i++)
	{
		frequency[str[i]]++;
	}

	for(int i=0;i<256;i++)
	{
		if(frequency[i]>0)
		{
			pq.push(Node(i,frequency[i]));
		}
	}

	while(pq.size()>1)
	{
		Node* l=new Node(pq.top());
		pq.pop();
		Node* r=new Node(pq.top());
		pq.pop();
		pq.push(Node(l,r));
	}

	cout<<"Huffman Coding of "<<str<<" is -\n";
	cout<<"\n\t"<<setw(10)<<"Data"<<setw(10)<<"Frequency"<<setw(15)<<"Code\n";
	pq.top().traverse();
}

int main()
{
	string str="aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff";
	huffmanCoding(str);
	return 0;
}