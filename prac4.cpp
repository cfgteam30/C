#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int max_ct=0;
        stack<int> S;
        S.push(-1);
        for(int i=0;i<n;i++){
            switch(s[i]){
                case '(':
                S.push(i);
                break;
                case ')':
                if()
            }
        }
        return max_ct;
    }
};

void solve(int tc){
    cout<<Solution().longestValidParentheses("(()((())))()")<<endl;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t=1;
  //init();
//   cin>>t;
  for(int z=0;z<t;z++)
  {
    solve(z+1);
  }
  return 0;
}