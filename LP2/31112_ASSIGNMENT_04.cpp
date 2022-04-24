//TODO: Implement NQueens Problem

#include <bits/stdc++.h>
using namespace std;

class NQueens
{
    int N;
    vector<vector<int>> board;

public:
    NQueens(int n)
    {
        N = n;
        for (int i = 0; i < N; i++)
        {
            vector<int> a;
            for (int j = 0; j < N; j++)
            {
                a.push_back(0);
            }
            board.push_back(a);
        }
    }

    void printSolution()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                printf(" %d ", board[i][j]);
            printf("\n");
        }
    }

    bool isSafe(int row, int col)
    {
        int i, j;

        for (i = 0; i < col; i++)
            if (board[row][i])
                return false;

        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                return false;

        return true;
    }

    bool solveNQUtil(int col)
    {
        if (col >= N)
            return true;
        for (int i = 0; i < N; i++)
        {
            if (isSafe(i, col))
            {
                board[i][col] = 1;

                if (solveNQUtil(col + 1))
                    return true;

                board[i][col] = 0; // BACKTRACK
            }
        }
        return false;
    }
    bool solveNQ()
    {
        if (solveNQUtil(0) == false)
        {
            printf("Solution does not exist");
            return false;
        }
        printSolution();
        return true;
    }
};

class Solution {
public:
    bool isSafe(int row,int col,int n){
        if(row<n && row>=0 && col<n && col>=0)
            return true;
        return false;
    }
    bool isBoardSafe(vector<string> &board ,int row ,int col,int n){
       
        int rowdia=row,coldia=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row=rowdia;
        col=coldia;
        while(row>=0){
            if(board[row][col]=='Q') return false;
            row--;
        }
        row= rowdia;
        while(col<n && row>=0){
            if(board[row][col]=='Q') return false;
            col++;
            row--;
        }
        return true;
    }
    void solve(int n, vector<vector<string>> &ans,vector<string> &board,int row){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(row,i,n) && isBoardSafe(board,row,i,n)){
                board[row][i]='Q';
                solve(n,ans,board,row+1);
                board[row][i]='.';
            }
        }
       
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
        board[i]=s;
        }
        solve(n,ans,board,0);
        return ans;
    }
};

int main()
{
    cout << "\nNQueens Problem using BackTracking approach: \n\n";
    int n;
    cout << "Enter the dimensions of the board: ";
    cin >> n;
    NQueens nq = NQueens(n);
    nq.solveNQ();
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