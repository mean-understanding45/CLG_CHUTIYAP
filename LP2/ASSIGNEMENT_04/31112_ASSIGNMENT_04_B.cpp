#include <bits/stdc++.h>
using namespace std;
#define N 8



class Solution {
public:

void solve(vector<vector<bool>>&grid, int row,vector<bool>& ndiag,vector<bool> &rdiag,vector<bool>&cols)
{
					
					
	if(row==grid.size())
		{
			display(grid);
			return;
	    }
    
     for(int col=0;col<grid[0].size();col++)
    { 
	if(ndiag[row+col]==false && rdiag[row-col+grid.size()]==false && cols[col]==false)
      {
        ndiag[row+col]=true;
        rdiag[row-col+grid.size()]=true;
        cols[col]=true;
        grid[row][col]=true;
        solve(grid,row+1,ndiag,rdiag,cols);
         grid[row][col]=false;
        ndiag[row+col]=false;
        rdiag[row-col+grid.size()]=false;
        cols[col]=false;
      }
        
    }
    
}
vector<vector<string>> ans;
void display(vector<vector<bool>>&grid){
    string a="";
    int n=grid.size();
    vector<string> row;
    for (int i = 0; i < n; ++i)
    {   
        a="";
        for (int j = 0; j < n; ++j)
        {
            if(grid[i][j]==true){
                a+="Q";
            }
            else{
                a+=".";
            }
        }
        row.push_back(a);
    }
    ans.push_back(row);
}

vector<vector<string>> solveNQueens(int n) 
{
   vector<vector<bool>> grid(n,vector<bool>(n,false));
    
    vector<bool> cols(n,false);
    vector<bool> ndiag(2*n-1,false);
    vector<bool>rdiag(2*n-1,false);
 
    solve(grid,0,ndiag,rdiag,cols);
    return ans;
    
}
};

int main()
{
	cout << "\nNQueens Problem using Branch and Bound approach: \n\n";
    int n;
    cout << "Enter the dimensions of the board: ";
    cin >> n;
    Solution s;
    vector<vector<string>> a=s.solveNQueens(n);
    cout<<"All Possible Solutions= "<<a.size()<<endl;    
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            cout<<a[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

