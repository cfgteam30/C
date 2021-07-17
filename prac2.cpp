// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    long long maxOfThree(long long  a,long long  b,long long  c){
        if(a>b)
            if(b>c)
                return a;
            else 
                if(a>c)
                    return a;
                else
                    return c;
        else//b>a
            if(c>b)
                return c;
            else//b>c
                return b;
        
    }
    int minIndex(int i,int j, long long a[]){
      if(a[i]<a[j])
        return i;
      return j;
    }
    int getMinIndex(int segT[], int i, int tl, int tr, long long arr[],int l,int r){
        if(tl>=l&&tr<=r)
            return segT[i];
        else if(tr<l||tl>r)
            return -1;
        else{
          int a=getMinIndex(segT,i*2+1,tl,(tr+tl+1)/2-1,arr,l,r);
          int b=getMinIndex(segT,i*2+2,(tr+tl+1)/2,tr,arr,l,r);
          if(a==-1)
            if(b==-1)
              return -1;
            else
              return b;
          else
            if(b==-1)
              return a;
            else
              return minIndex( a , b , arr  );
        }
    }
    long long getMaxArea(int segT[], long long arr[],int l,int r,int n){
      // cout<<"max from "<<l<<" to "<<r<<endl;
        if(l>r)
            return 0;
        else if(l==r)
            return arr[l];
        int i=getMinIndex(segT,0,0,n-1,arr,l,r);
        long long a=getMaxArea(segT, arr,l,i-1,n),b=getMaxArea(segT, arr, i+1, r, n),c=arr[i]*(r-l+1) ;
        long long res= maxOfThree( a,b,c); 
        // cout<<"max from "<<l<<" to "<<r<<", max of "<<a<<", "<<b<<", "<<c<<" = "<<res<<endl;
        return res;
    }
    long long makeSegT(int segT[],int i, long long arr[],int l,int r){
        if(l==r)
            segT[i]=l;
        else
            segT[i]=minIndex( makeSegT(segT,2*i+1,arr,l,(l+r+1)/2-1) , makeSegT(segT,2*i+2,arr,(l+r+1)/2,r) , arr );
        return segT[i];
    }
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        if(n<=0)
            return 0;
        else if(n==1)
            return arr[0];
        int segTcapacity=2*(int)pow(2,(int)ceil(log2(n))) -1;
        int segT[segTcapacity];
        int i = makeSegT(segT,0,arr,0,n-1);
        return maxOfThree( getMaxArea(segT,arr,0,i-1,n),getMaxArea(segT,arr,i+1,n-1,n),arr[i]*n ); 
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    // cin>>t;
    t=1;
    while(t--)
    {
        int n;
        // cin>>n;
        n=11;
        
        long long arr[n]={7, 12, 8, 12, 1, 3, 6, 5,0,23,2};
        // for(int i=0;i<n;i++)
        //     cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends