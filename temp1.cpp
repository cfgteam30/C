#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define p(x,y) pair<x,y>
// #define oset(x) tree<x, null_type, less<x>, rb_tree_tag, tree_order_statistics_node_update>
// #define all(x) (x).begin(),(x).end()
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// #define ll long long
// #define int ll
#define scan(a) for(auto &it:a)cin>>it;
#define print(a) {for(auto it:a)cout<<it<<" ";cout<<endl;}
#define finish(a) {cout<<a<<"\n";return;}
#define out(a) {cout<<a<<"\n";}
#define fr(i,n) for(int i=0;i<n;i++)
#define fri(i,j,n) for(int i=j;i<n;i++)

void solve(int testcase)
{
    int n;
    cin>>n;
    int a[n];
    scan(a);
    // int last_max=a[0];
    // unordered_map<int,int> un;
    // fri(i,1,n){
    //     if(a[i]<last_max)
    //         un[a[i]]++;
    //     else
    //         last_max=a[i];
    // }

    bool dp[n][n];
    dp[0][0]=1;
    for(int l=n-1;l>=1;l--){
        for(int i=0;i+l<=n;i++){
            dp[i][i+l-1]=
        }
    }
    
}
int32_t main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t=1;
  //init();
  cin>>t;
  for(int z=0;z<t;z++)
  {
    solve(z);
  }
  return 0;
}