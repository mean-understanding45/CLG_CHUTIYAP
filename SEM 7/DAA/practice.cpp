// //Assignment 4

// #include <bits/stdc++.h>

// using namespace std;

// class NQueens{
// public:
//     int N;

//     NQueens()
//     {
//         cout<<"Enter the size of the board: ";
//         cin>>N;
//     }

//     bool isSafe(int r,int c)
//     {
//         if(r>=0 && r<N && c>=0 && c<N) return true;
//         return false;
//     }

//     bool isBoardSafe(vector<string>& board,int r,int c)
//     {
//         int rt=r;
//         int ct=c;

//         //up
//         while(r>=0)
//         {
//             if(board[r][c]=='Q') return false;
//             r--;
//         }

//         //down
//         r=rt;
//         c=ct;
//         while(r<N)
//         {
//             if(board[r][c]=='Q') return false;
//             r++;
//         }

//         //right
//         r=rt;
//         c=ct;
//         while(c<N)
//         {
//             if(board[r][c]=='Q') return false;
//             c++;
//         }

//         //left
//         r=rt;
//         c=ct;
//         while(c>=0)
//         {
//             if(board[r][c]=='Q') return false;
//             c--;
//         }

//         //upper left
//         r=rt;
//         c=ct;
//         while(r>=0 && c>=0)
//         {
//             if(board[r][c]=='Q') return false;
//             r--;
//             c--;
//         }

//         //upper right
//         r=rt;
//         c=ct;
//         while(r>=0 && c<N)
//         {
//             if(board[r][c]=='Q') return false;
//             r--;
//             c++;
//         }

//         //lower left
//         r=rt;
//         c=ct;
//         while(r<N && c>=0)
//         {
//             if(board[r][c]=='Q') return false;
//             r++;
//             c--;
//         }

//         //lower right
//         r=rt;
//         c=ct;
//         while(r<N && c<N)
//         {
//             if(board[r][c]=='Q') return false;
//             r++;
//             c++;
//         }

//         return true;
//     }

//     void solve(vector<vector<string>>& ans,vector<string>& board,int r,int ri,int ci)
//     {
//         if(r==N)
//         {
//             ans.push_back(board);
//             return;
//         }
//         else
//         {
//             for(int i=0;i<N;i++)
//             {
//                 if(r==ri && i==ci)
//                 {
//                     solve(ans,board,r+1,ri,ci);
//                 }
//                 else if(isSafe(r,i) && isBoardSafe(board,r,i))
//                 {
//                     board[r][i]='Q';
//                     solve(ans,board,r+1,ri,ci);
//                     board[r][i]='.';
//                 }
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(vector<string>& board,int ri,int ci)
//     {
//         vector<vector<string>> ans;
//         solve(ans,board,0,ri,ci);
//         return ans;
//     }
// };

// int main()
// {
//     NQueens nq;
//     vector<string> board(nq.N,string(nq.N,'.'));
//     int ri,ci;
//     cout<<"Enter the starting row and column of first queen: ";
//     cin>>ri>>ci;

//     board[ri][ci]='Q';
//     for(auto x:board)
//     {
//         cout<<x<<endl;
//     }
//     cout<<"\n\n\n";

//     vector<vector<string>> ans=nq.solveNQueens(board,ri,ci);
//     cout<<ans.size();
//     cout<<"\n";
//     for(int i=0;i<ans.size();i++)
//     {
//         for(auto x:ans[i])
//         {
//             cout<<x<<endl;
//         }
//         cout<<"\n\n\n";
//     }

//     return 0;
// }

//Assignment 5

#include <bits/stdc++.h>
using namespace std;

class Sorting{
    vector<int> arr;
public:
    Sorting()
    {
        int n;
        cout<<"Enter the total number of elements: ";
        cin>>n;
        int t;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter the number: ";
            cin>>t;
            arr.push_back(t);
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
        int num=rand();
        int ri=l+num%(h-l+1);
        swap(arr[ri],arr[h]);
        partition(l,h);
        return ri;
    }

    void r_quickSort(int l,int h)
    {
        if(l>=h) return;
        int ri=r_partition(l,h);
        r_quickSort(l,ri-1);
        r_quickSort(ri+1,h);
    }

    void displayArray()
    {
        for(auto x:arr)
        {
            cout<<x<<" "; 
        }
        cout<<endl;
    }

};

int main()
{
    Sorting s;
    s.r_quickSort(0,s.getArraySize()-1);
    s.displayArray();
    return 0;
}