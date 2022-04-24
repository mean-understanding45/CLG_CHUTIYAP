#include <bits/stdc++.h>

using namespace std;

class GraphMR{ //Matrix Representation

private:
    
public:
    
    int v;
    int** p;  //no of vertices;

    bool* vis=new bool[v]; //visited vertices (for recursive DFS)

    GraphMR(int v)
    {
        this->v=v;  //initialising the number of vertices;
        p=new int* [v];
        for(int i=0;i<v;i++){
            p[i] = new int[v];
        }
        for(int i=0;i<v;i++)
        {
            for(int j=i;j<v;j++)
            {
                p[i][j]=0;
                p[j][i]=0;
            }
        }
    }

    void setGraph()
    {
        string s;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<"Are the vertices - "<<i<<j<<" connected? (Enter 1 if connected else anything)  ";
                cin>>s;
                if(s=="1")
                {
                    p[i][j]=1;
                }
            }
        }
    }

    void setWeightedGraph()
    {
        string s;
        int w;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<"Are the vertices - "<<i<<j<<" connected? (Enter 1 if connected else anything)  ";
                cin>>s;
                if(s=="1")
                {
                    cout<<"Enter the weight of the edge: ";
                    cin>>w;
                    p[i][j]=w;
                }
            }
        }
    }

    void printGraph(){
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void printEdges()
    {
        cout<<"Edges - {";
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(p[i][j]==1)
                {
                    cout<<"("<<i<<","<<j<<"),";
                }
            }
        }
        cout<<"}\n";
    }

    void BFS()
    {
        int startV;
        cout<<"Enter the start vertex for BFS: ";
        cin>>startV;
        //bool* visited = new bool[v];
        for(int i=0;i<v;i++) vis[i]=false; // marking all the vertices as unvisited

        queue<int> q; //supplementary data structure

        q.push(startV);
        int vertex;
        while(!q.empty()) 
        {
            vertex=q.front(); 
            cout<<vertex<<" ";
            q.pop();
            vis[vertex]=true;
            for(int i=0;i<v;i++) //exploring the neighbours first
            {
                if(p[vertex][i]==1 && !vis[i])
                {
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        cout<<"\n";
    }

    void setVisitedFalse()
    {
        for(int i=0;i<this->v;i++)  this->vis[i]=false;
    }

    void DFS()
    {
        int startV;
        cout<<"\nEnter the starting vertex for DFS: ";
        cin>>startV;
        //bool* visited=new bool[v];
        for(int i=0;i<v;i++) vis[i]=false;

        stack<int> st;
        st.push(startV);

        int vertex;
        while(!st.empty())
        {
            vertex=st.top();
            st.pop();
            cout<<vertex<<" ";
            vis[vertex]=true;
            for(int i=0;i<v;i++) //exploring the neighbours of the neighbours (as stack is used the lastly added vertex will occur first in DFS)
            {
                if(p[vertex][i]==1 && !vis[i])
                { 
                    st.push(i);
                    vis[i]=true;
                }
            }
        }
        cout<<"\n";
    }

    
    void recursiveDFS(int vertex)
    {
        vis[vertex]=true;

        //cout<<vertex<<" ";
        for(int i=0;i<v;i++)
        {
            if(!vis[i] && p[vertex][i]==1)
            {
                vis[i]=true;
                recursiveDFS(i);
            }
        }
    }
};