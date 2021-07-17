#include<bits/stdc++.h>
#include"Graph.hpp"
#define sqr(x) x*x

using namespace std;

int main(){
    Graph G(5);
    G.add(0,{{1,3},{2,8},{4,-4}});
    G.add(1,{{3,1},{4,7}});
    G.add(2,{{1,4}});
    G.add(3,{{0,2},{2,-5}});
    G.add(4,{{3,6}});
    for(auto i:G.jhoson()){
        for(auto j:i)
            cout<<j<<"\t";
        cout<<"\n";
    }
    cout<<"\n";

}