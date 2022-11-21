/*
Implement Greedy search algorithm for any of the following application:
I.
Selection Sort
II. Minimum Spanning Tree
III. Single-Source Shortest Path Problem
IV.
Job Scheduling Problem
V. Prim's Minimal Spanning Tree Algorithm
VI.
Kruskal's Minimal Spanning Tree Algorithm
VII.
Dijkstra's Minimal Spanning Tree Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    map<int,vector<pair<int,int>>> graph;
    int v; //no of vertices;
    Graph(int nv)
    {
        this->v=nv;
    }
    void setGraph()
    {
        int n;
        cout<<"Enter the number of edges present in the graph: ";
        cin>>n;
        int a,b,w;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter the first vertex: ";
            cin>>a;
            cout<<"Enter the second vertex: ";
            cin>>b;
            cout<<"Enter the weight of the edge: ";
            cin>>w;
            graph[a].push_back({b,w});
        }
    }
    void printEdges()
    {
        for(auto x:graph)
        {
            for(auto y:x.second)
            {
                cout<<"("<<x.first<<","<<y.first<<","<<y.second<<"),";
            }
        }
    }
};

void primsMST(Graph g)
{
    //TODO: To find the minimum spanning tree of the given graph
    vector<int> dist(g.v,INT_MAX);
    vector<int> from(g.v,-1);
    vector<bool> vis(g.v,false);
    Graph mst(g.v);
    vis[0]=true;
    for(auto x:g.graph[0])
    {
        dist[x.first]=x.second;
        from[x.first]=0;
    }
    int vertex;
    int u;
    int minDist=INT_MAX;
    int n=g.v-1;
    while(n>0)
    {
        minDist=INT_MAX;
        for(int i=0;i<g.v;i++)
        {
            if(!vis[i] && dist[i]<minDist)
            {
                vertex=i;
                minDist=dist[i];
            }
        }
        vis[vertex]=true;
        u=from[vertex];

        mst.graph[u].push_back({vertex,minDist});

        for(auto x:g.graph[vertex])
        {
            if(!vis[x.first] && x.second<dist[x.first])
            {
                dist[x.first]=x.second;
                from[x.first]=vertex;
            }
        }
        n--;
    }
    cout<<"\nThe edges in minimum spanning tree by Prim's MST Algorithm is - (first vertex,second vertex,weight)\n";
    mst.printEdges();
    cout<<"\n\n\nThe cost of MST is = ";
    int cost=0;
    for(auto x:mst.graph)
    {
        for(auto y:x.second)
        {
            cost+=y.second;
        }
    }
    cout<<cost<<endl;
}

int main()
{
bool cont=true;
    bool isEmpty=true;
    Graph g=Graph(1);
    int choice;
    while(cont)
    {
        cout<<"\nEnter your choice: ";
        cout<<"\n1. Set new graph";
        cout<<"\n2. Print the graph";
        cout<<"\n3. Print the cost of minimum spanning tree";
        cout<<"\n4. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int v;
                cout<<"\nEnter the number of vertices: ";
                cin>>v;
                g=Graph(v);
                g.setGraph();
                isEmpty=false;
                break;
            case 2:
                if(!isEmpty)
                {
                    cout<<"\n\n";
                    g.printEdges();
                    cout<<"\n\n";
                }
                else cout<<"\nPlease Set the graph first\n";
                break;
            case 3:
                if(!isEmpty)
                {
                    primsMST(g);
                }
                else cout<<"\nPlease Set the graph first\n";
                break;            
            case 4:
                cout<<"\nTerminated";
                cont=false;
                break;
        }
    }
    return 0;
}