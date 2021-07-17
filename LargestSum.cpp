#include<iostream> 

using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
    int p=0,q=0,r=0,s=0;
int max_so_far = a[0]; 
int curr_max = a[0]; 

for (int i = 1; i < size; i++) 
{ 
		if(curr_max+a[i]<=a[i]){
            curr_max+=a[i];
            q=i;
        }else{
            curr_max=a[i];
            p=i;q=i;
        }
		if(max_so_far>curr_max){
            max_so_far=curr_max;
            r=p;s=q;
        }
} 
cout<<"from "<<r+1<<" to "<<s+1<<"\n";
return max_so_far; 
} 

/* Driver program to test maxSubArraySum */
int main() 
{ 
int a[] = {-1 ,-2, 7, -8, 10, -3, -4, -5}; 
int n = sizeof(a)/sizeof(a[0]); 
// tuple<int,int,int> ans;
// ans = ;
cout << "Maximum contiguous sum is "<<maxSubArraySum(a, n) ; 
return 0; 
} 

int32_t remove_padding(
uint8_t* buf,  uint32_t buflen) 
{  uint8_t padlen = buf[buflen-1];  uint32_t i;
for (i = 0; i < padlen; i++) 
{  if (buf[buflen-i-1] != padlen)
   return -1;
   buf[buflen-i-1] = 0;
}
return padlen;
}
