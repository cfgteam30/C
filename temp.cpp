// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Fancy {
private: 
    int mod=pow(10,9);
    class Op{
        public:
        bool id;
        int val;
        int midx; 
        Op(bool i,int v,int m) : id(i), val(v), midx(m) {}
        void print(){
            cout<<"i="<<id<<" v="<<val<<" idx="<<midx;
        }
    };
    vector<int> seq;
    vector<Op> ops;
public:
    Fancy() {
        
    }
    
    void append(int val) {
        seq.push_back(val);
    }
    
    void addAll(int inc) {
        ops.push_back(Op(0,inc,seq.size()-1));
    }
    
    void multAll(int m) {
        ops.push_back(Op(1,m,seq.size()-1));
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size())
            return -1;
        unsigned int res=seq[idx];
        cout<<"currently :";
        for(auto op:ops)
            op.print();
        cout<<"\n";
        for(auto op:ops){
            if(idx>op.midx)
                continue;
            if(op.id)
                res*=op.val;
            else
                res+=op.val;
        }
        return res%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */


// { Driver Code Starts.

int main() {
    int t;
    // cin >> t;
    t=1;
    while (t--) {
         Fancy* obj = new Fancy();
        obj->append(2);
        obj->addAll(3);
        obj->append(7);
        obj->multAll(2);
        cout<<obj->getIndex(0)<<"\n";
        obj->addAll(3);
        obj->append(10);
        obj->multAll(2);
        cout<<obj->getIndex(0)<<"\n";
        cout<<obj->getIndex(1)<<"\n";
        cout<<obj->getIndex(2)<<"\n";
    }
    return 0;
} 
