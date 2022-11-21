/*
 * Problem Statement :- Design n-Queens matrix having first Queen placed. Use backtracking
 * 						to place remaining Queens to generate the final n-queen's matrix.
 *
 * Time Complexity  : O(n!)
 * Space Complexity : O(n)
 */

#include <bits/stdc++.h>

using namespace std;

class NQueens{
public:
	int N;
	NQueens()
	{
		cout<<"Enter the size of the board: ";
		cin>>N;
	}

	bool isSafe(int r,int c)
	{
		if(r>=0 && r<N && c>=0 && c<N) return true;
		return false;
	}

	bool isBoardSafe(vector<string>& board,int r,int c)
	{
		int rt=r,ct=c;

		//upper left
		while(r>=0 && c>=0)
		{
			if(board[r][c]=='Q') return false;
			r--;
			c--;
		}

		//upper
		r=rt;
		c=ct;
		while(r>=0)
		{
			if(board[r][c]=='Q') return false;
			r--;
		}

		//upper right
		r=rt;
		c=ct;
		while(r>=0 && c<N)
		{
			if(board[r][c]=='Q') return false;
			r--;
			c++;
		}

		//left
		r=rt;
		c=ct;
		while(c>=0)
		{			
			if(board[r][c]=='Q') return false;
			c--;
		}

		//right
		r=rt;
		c=ct;
		while(c<N)
		{			
			if(board[r][c]=='Q') return false;
			c++;
		}

		//lower
		r=rt;
		c=ct;
		while(r<N)
		{			
			if(board[r][c]=='Q') return false;
			r++;
		}

		//lower left
		r=rt;
		c=ct;
		while(c>=0 && r<N)
		{			
			if(board[r][c]=='Q') return false;
			c--;
			r++;
		}

		//lower right
		r=rt;
		c=ct;
		while(c<N && r<N)
		{			
			if(board[r][c]=='Q') return false;
			c++;
			r++;
		}
		return true;
	}

	void solve(vector<vector<string>>& ans,vector<string>& board,int r,int ir,int ic)
	{

		//ir = first q row
		//ic = first q col

		if(r==N)
		{
			ans.push_back(board);
			return;
		}
		else
		{
			for(int i=0;i<N;i++)
			{
				if(r==ir && i==ic)
				{
					solve(ans,board,r+1,ir,ic);
				}
				else if(isSafe(r,i) && isBoardSafe(board,r,i))
				{
					board[r][i]='Q';
					solve(ans,board,r+1,ir,ic);
					board[r][i]='.';
				}
			}
		}
	}

	vector<vector<string>> solveNQueens(vector<string>& board,int ir,int ic)
	{
		vector<vector<string>> ans;
		solve(ans,board,0,ir,ic);
		return ans;
	}
	
};

int main()
{
	NQueens nq;
	vector<string> board(nq.N,string(nq.N,'.'));
	cout<<"Enter the starting row and column of the first queen: ";
	int r,c;
	cin>>r>>c;
	board[r][c]='Q';
	vector<vector<string>> ans=nq.solveNQueens(board,r,c);
	for(int i=0;i<ans.size();i++)
	{
		for(auto x:ans[i])
		{
			for(auto y:x)
			{
				cout<<y<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n\n\n";
	}
	return 0;
}