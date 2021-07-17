#include<bits/stdc++.h> 

using namespace std; 

typedef struct subarrar{
    int start;
    int stop;
    int sum;
} subarr;

subarr maxSubArraySum(vector<int> a) 
{ 
    int p=0,q=0,r=0,s=0;
int max_so_far = a[0]; 
int curr_max = a[0]; 

for (int i = 1; i < a.size(); i++) 
{ 
		if(curr_max+a[i]>=a[i]){
            curr_max+=a[i];
            q=i;
        }else{
            curr_max=a[i];
            p=i;q=i;
        }
		if(max_so_far<curr_max){
            max_so_far=curr_max;
            r=p;s=q;
        }
} 
// cout<<"from "<<r+1<<" to "<<s+1<<"\n";
// return max_so_far; 
    return (subarr){r,s,max_so_far};
} 

/* Driver program to test maxSubArraySum */
int main() 
{ 
    int m=4,n=5;
    int a[m][n]={{1,2,-1,-4,-20},{-8,-3,4,2,1},{3,8,10,1,3},{-4,-1,1,7,-6}};
    int m0,m1,m2,m3,mx=-INT32_MAX;
    vector<int> t(n);
    subarr res;
    // for(int j=0;j<n;j++){
    //     for(int i=0;i<n;i++)
    //         cout<<a[j][i]<<" ";
    //     cout<<"\n";
    // }
    for(int i=0;i<m;i++){
        t=vector<int>(n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++)
                t[k]+=a[j][k];
            res=maxSubArraySum(t);
            if(res.sum>mx){
                mx=res.sum;
                m0=res.start;
                m1=i;
                m2=res.stop;
                m3=j;
            }
        }
    }

    for(int j=m1;j<=m3;j++){
        for(int i=m0;i<=m2;i++)
            cout<<a[j][i]<<" ";
        cout<<"\n";
    }
}