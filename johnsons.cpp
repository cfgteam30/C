#include<iostream>
#include<string.h>
#include<windows.h>
#include<vector>
#include<stdlib.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct node {
    int destination;
    int weight;

    node (int d,int w){
        destination = d;
        weight = w;
    }
};

void bellman(vector<node> g[],int n,int s,vector<int> &h){


    vector<int> dist(n+1,999);

    dist[s]=0;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int u = j;
            for(int v=0;v<g[u].size();v++){
                int d = g[u][v].destination;
                dist[d] = min(dist[d],dist[u]+g[u][v].weight);
            }
        }
    }

    // for(int j=0;j<=n;j++){
    //     int u = j;
    //     for(int v=0;v<g[u].size();v++){
    //         if(dist[v]<dist[u]+g[u][v].weight){
    //             cout<<"Negative cycle\n";
    //             exit(0);
    //         }
    //     }
    // }

    //dist.erase(dist.begin()+s);
    h = dist;
    cout<<"\nH values\n";
    for(int i=0;i<=n;i++)
        cout<<h[i]<<" ";
    cout<<"\n\n";
}

void displayGraph(vector<node> g[],int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<g[i].size();j++)
            cout<<i<<" "<<g[i][j].destination<<" "<<g[i][j].weight<<"\n";
    }
}


void addNode(vector<node> g[],int n){
    
    for(int i=0;i<n;i++)
    {
        node no = node(i,0);
        g[n].push_back(no);
    }
    // cout<<"\n\n";
    // displayGraph(g,n+1);
    // cout<<"\n\n";
}


void reweight(vector<node> g[],int n,int s){
    vector<node> newGraph[n+1];
    for(int i=0;i<n;i++)
        newGraph[i] = g[i];
    addNode(newGraph,n);
    vector<int> h(n+1);
    bellman(newGraph,n,n,h);

    
    for(int i=0;i<n;i++){
        for(int j=0;j<newGraph[i].size();j++){
            int d = newGraph[i][j].destination;
            newGraph[i][j].weight = newGraph[i][j].weight+h[i]-h[d];
            cout<<i<<"-->"<<newGraph[i][j].destination<<" "<<newGraph[i][j].weight<<"\n";
        }
    }

    vector<int> d(n+1);
    bellman(newGraph,n-1,s,d);

    cout<<"\n";
    for(int i=0;i<n;i++){
            cout<<"Old "<<s<<"-->"<<i<<":"<<d[i]<<"\n";
            d[i]  = d[i]-h[s]+h[i];
            SetConsoleTextAttribute(hConsole, 2);
            cout<<s<<"-->"<<i<<":"<<d[i]<<"\n\n";
            SetConsoleTextAttribute(hConsole, 7);
    }

}


void constructGraph(vector<node> g[],int n,int m){
    cout<<"Source   Destination   Weight\n";
    int s,d,w;
    for(int i=0;i<m;i++)
    {
        cin>>s>>d>>w;
        node n = node(d,w);
        g[s].push_back(n);
    }
}



int main()
{
    int n,m,s;
    cout<<"Enter vertices and edges and source\n";
    cin>>n>>m>>s;
    vector<node> graph[n];
    constructGraph(graph,n,m);
    //displayGraph(graph,n);
    reweight(graph,n,s);
    return 0;
}