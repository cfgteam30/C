#include<bits/stdc++.h>

using namespace std;

#define print(a) {for(auto i:a) cout<<i<<"\t"; cout<<endl;}
#define inf INT_MAX

typedef struct edge{
    int u;
    int v;
    int wt;
} edge;
class Graph{
    private:
    vector<map<int,int>> adjacency_list;
    int nodes;
    bool directed=true;

    public:

    Graph(int _nodes,bool _directed=true): nodes(_nodes), directed(_directed) { 
        adjacency_list=vector<map<int,int>>(nodes);
    }
    void add(edge e){
        adjacency_list[e.u][e.v]=e.wt;
        if(!directed)
            adjacency_list[e.v][e.u]=e.wt;
    }
    void add(int u,list<pair<int,int>> vw){
        for(auto p:vw)
            adjacency_list[u][p.first]=p.second;
    }
    
    void static printAdj(vector<map<int,int>> adjacency_list){
        for(int i=0;i<adjacency_list.size();i++){
            cout<<i<<": [ ";
            for(auto p:adjacency_list[i]){
                cout<<p.first<<'('<<p.second<<"), ";
            }
            cout<<"]\n";
        }
    }

    void static printDist(vector<int>&dist){
        for(int i=0;i<dist.size();i++){
            if(dist[i]!=inf) cout<<i<<'('<< dist[i]<<')' <<"\t";
            else  cout<<i<<'('<< "inf"<<')' <<"\t";
        }
        cout<<"\n";
    }
    
    
    vector<int> dijikstra(int src){
        class Heap{

            private:
                int N=0;
                vector<int> heap_array;
                vector<int> node_mapping;
                vector<int> *distance;

                bool lessThan(int i,int j){
                    return (*distance)[heap_array[i]]<(*distance)[heap_array[j]];
                }
                void swp(int i,int j){
                    node_mapping[heap_array[i]]=j;
                    node_mapping[heap_array[j]]=i;
                    int t=heap_array[i];
                    heap_array[i]=heap_array[j];
                    heap_array[j]=t;
                }
                void buildheap(){
                    for(int i=(N-2)/2;i>=0;i--)
                        heapify(i);
                    
                }
                void heapify(int i){
                    int l=i*2+1,r=2*i+2,s=i;
                    if(l<N && lessThan(l,s))
                        s=l;
                    if(r<N && lessThan(r,s))
                        s=r;
                    if(s!=i){
                        swp(s,i);
                        heapify(s);
                    }
                }

            public:
                Heap(int _n,vector<int> *_dist):N(_n), distance(_dist){ 
                          
                    for(int i=0;i<N;i++){
                        heap_array.push_back(i);
                        node_mapping.push_back(i);
                    }
                    buildheap();
                }
                void printH(){
                    for(int i=0;i<N;i++)
                        cout<<i<<"\t";
                    cout<<"\n";
                    for(int i=0;i<N;i++)
                        cout<<(*distance)[heap_array[i]]<<"\t";
                    cout<<"\n\n";
                }
                void update(int n,int v){
                    int temp=(*distance)[n];
                    (*distance)[n]=v;
                    if(v<temp){
                        int child=node_mapping[n];
                        int parent=(child-1)/2;
                        while(parent>=0 && lessThan(child,parent)){
                            swp(parent,child);
                            child=parent;
                            parent=(child-1)/2;
                        }
                    }
                }
                int pop(){
                    int node=heap_array.front();
                    swp(0,N-1);
                    N--;
                    heapify(0);
                    return node;
                }
                bool empty(){
                    return N==0;
                }
        };

        vector<int> distance(nodes,inf);
        distance[src]=0;
        vector<bool> vis(nodes,0);
        Heap heap(nodes,&distance);
        while(!heap.empty()){
            // heap.print();
            int cur=heap.pop();
            vis[cur]=1;
            for(auto neighbour:adjacency_list[cur])
                if(!vis[neighbour.first] && distance[cur]+neighbour.second<distance[neighbour.first])
                    heap.update(neighbour.first,distance[cur]+neighbour.second);
            
        }
        return distance;
    }

    vector<int> bellmenford(int src){
        vector<int> distance(nodes,inf);
        distance[src]=0;
        cout<<"bellmanford(src:"<<src<<")\n";
        for(int i=0;i<nodes;i++){
            if(i==src)
                continue;
            cout<<i<<". relaxed: ";
            for(int u=0;u<nodes;u++){
                for(auto e:adjacency_list[u])
                    if(distance[u]!=inf && distance[e.first]>distance[u]+e.second){
                        distance[e.first]=distance[u]+e.second;
                        cout<<'<'<<u<<','<<e.first<<'>'<<' ';
                    }
            }
            cout<<"\n";
            printDist(distance);
        }
        for(int u=0;u<nodes;u++)
            for(auto e:adjacency_list[u])
                if(distance[e.first]>distance[u]+e.second){
                    cout<<"contains negaive weight cycle";
                    return {};
                }
        return distance;
    }

    vector<vector<int>> jhoson(){

        adjacency_list.push_back(map<int,int>());
        for(int i=0;i<nodes;i++)
            adjacency_list[nodes][i]=0;
        nodes++;

        auto dist=bellmenford(nodes-1);
        if(dist.size()==0)
            return {{}};
        cout<<"result :\n";
        printAdj(adjacency_list);
        cout<<"\n";
        
    
        auto _adjacency_list(adjacency_list);
        for(int u=0;u<nodes;u++)
            for(auto e:adjacency_list[u])
                adjacency_list[u][e.first]+=dist[u]-dist[e.first];
        cout<<"reweighted :\n";
        printAdj(adjacency_list);

        adjacency_list.pop_back();
        _adjacency_list.pop_back();
        nodes--;

        vector<vector<int>> all_src_dist;
        for(int u=0;u<nodes;u++){
            all_src_dist.push_back(dijikstra(u));
            for(int v=0;v<nodes;v++)
                all_src_dist.back()[v]+=dist[v]-dist[u];
        }
        
        adjacency_list=_adjacency_list;
        return all_src_dist;
    }  
};