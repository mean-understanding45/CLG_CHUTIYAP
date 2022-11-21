/*
 * Problem Statement :- Write a program to solve a 0-1 Knapsack problem using dynamic
 * 						programming or branch and bound strategy.
 *
 * Time complexity  : O(n*c)      (n=>number of elements  c=>capacity of knapsack)
 * Space Complexity : O(n*c)
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(vector<int>& weights,vector<int>& values,int ind,int c)
{
    if(ind==0 && weights[ind]>c)
    {
        return 0;
    }
    else if(ind==0 && weights[ind]<=c)
    {
        return values[ind];
    }
    
    if(dp[ind][c]!=-1) return dp[ind][c];
    
    int notPick=solve(weights,values,ind-1,c);
    int pick=0;
    
    if(weights[ind]<=c) pick=values[ind]+solve(weights,values,ind-1,c-weights[ind]);
    return dp[ind][c]=max(pick,notPick);
}

int main()
{
    int n,c;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>c;

    vector<int> weights,values;
    int tw,tv;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the weight and its value: ";
        cin>>tw>>tv;
        weights.push_back(tw);
        values.push_back(tv);
    }

    dp=vector<vector<int>>(n,vector<int>(c+1,-1));

    cout<<"Max Value is - "<<solve(weights,values,n-1,c);
    return 0;
}