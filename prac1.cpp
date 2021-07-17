#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define p(x,y) pair<x,y>
// #define oset(x) tree<x, null_type, less<x>, rb_tree_tag, tree_order_statistics_node_update>
// #define all(x) (x).begin(),(x).end()
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
// #define int ll
#define scan(a)      \
  for (auto &it : a) \
    cin >> it;
#define print(a)         \
  {                      \
    for (auto it : a)    \
      cout << it << " "; \
    cout << endl;        \
  }
#define finish(a)      \
  {                    \
    cout << a << "\n"; \
    return;            \
  }
#define out(a)         \
  {                    \
    cout << a << "\n"; \
  }
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr_(i, j, n) for (int i = j; i < n; i++)
void swp(int *a, int *b)
{
  *a += *b;
  *b = *a - *b;
  *a -= *b;
}

void solve(int tc)
{
  ll n,c;
  cin>>n>>c;
  ll ct=n;
  // vector<int> mp(10000000000000,0);
  // fr(i,n){
  //   ll x,y;
  //   cin>>x>>y;
  //   for(ll j=x+1;j<y;j++){
  //     mp[j]++;
  //   }
  // }
  // sort(mp.begin(),mp.end());
  // for(ll i;i<10000000000000;i++)
  //   ct+=mp[i];
  fr(i,n){
    ll x,y;
    cin>>x>>y;
    segment()
  }
  
  cout<<"Case #"<<tc<<": "<<ct<<endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  //init();
  cin >> t;
  for (int z = 0; z < t; z++)
  {
    solve(z + 1);
  }
  return 0;
}