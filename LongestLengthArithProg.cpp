// C++ implementation to find the number closest to n 
// and divisible by m 
#include <bits/stdc++.h> 
  
using namespace std; 

int Solution(vector<int> A) 
{ 
    int i,j,k,res=2,n=A.size();
    vector<vector<int>> dp(n,vector<int>(n,2));
    
    for(j=n-2;j>0;j--)
        for(i=j-1,k=j+1 ; i>=0 && j<n; )
            if(A[i]+A[k]==2*A[j]){
                dp[i][j]=dp[j][k]+1;
                res=max(res,dp[i][j]);
                i--;k++;
            }else if(A[i]+A[k]<2*A[j])
                k++;
            else
                i--;
                
    return res;

} 
  
// Driver Code 
int main() 
{ 
    vector<int> a({8,11,13,14,17,20,21,25}); 
    cout << Solution(a) << endl; 
    return 0; 
} 