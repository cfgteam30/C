#include<iostream>
#include<windows.h>
#include<math.h>
#include<vector>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// vector<int> calculateTextHash(string t,int m,int n,int q){
//     vector<int> textHash(n-m+1);
//     int i = 0;
//     int sum = 0;
//     int term = 1;
//     for(int j=0;j<n-m+1;j++)
//     {
//         int k = m-1;
//         term = 1;
//         sum = 0;
//         while(k>=0)
//         {
//             //cout<<t[j+k];
//             sum=(sum+term*(t[j+k]-'a'+1))%q;
//             term = term*10;
//             k--;
//         }
//         //cout<<"\n";
//         textHash[i++] = sum;
//     }
    
//     return textHash;
// }

// void printHash(vector<int> hash,int n)
// {
//     for(int i=0;i<n;i++)
//         cout<<hash[i]<<" ";
//     cout<<"\n";
// }

// int calculatePatternHash(string p,int m,int q)
// {
//     int patHash=0;
//     for(int i=0;i<m;i++)
//         patHash=  
// }

// void kmp(vector<int> textHash,int patternHash,string t,string p,int m)
// {
//     int spuriousHit = 0;
//     for(int i=0;i<textHash.size();i++)
//     {
//         SetConsoleTextAttribute(hConsole, 3);
//         cout<<"Hash of "<<t.substr(i,m)<<" = "<<textHash[i]<<"\n";
//         SetConsoleTextAttribute(hConsole, 7);
//         if(patternHash==textHash[i])
//         {

//             if(t.substr(i,m)==p)
//             {
//                 SetConsoleTextAttribute(hConsole, 2);
//                 cout<<"Pattern found between "<<i<<" and "<<i+m-1<<" "<<t.substr(i,m)<<"\n";
//                 SetConsoleTextAttribute(hConsole, 7);
//             }
//             else
//             {
//                 spuriousHit++;
//                 SetConsoleTextAttribute(hConsole, 4);
//                 cout<<"Spurious Hit "<<spuriousHit<<" "<<t.substr(i,m)<<"\n";
//                 SetConsoleTextAttribute(hConsole, 7);
//             }
//         }
//     }
// }

int spuriousHit=0;
int charToInt(char c){
    return c-'0';
}
void KMP(string T,string P,int d,int q){
    int n=T.length();
    int m=P.length();
    int h=((int)pow(d,m-1))%q;
    int p=0;
    int t=0;
    for(int i=0;i<m;i++){
        p=(p*d+charToInt(P[i]))%q;
        t=(d*t+charToInt(T[i]))%q;
    }
    SetConsoleTextAttribute(hConsole, 6);
    cout<<"Hash of pattern = "<<p<<"\n";
    if(p<0) p+=q;
    if(t<0) t+=q;
    for(int s=0;s<=n-m;s++){
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"Hash of "<<T.substr(s,m)<<" = "<<t<<"\n";
        if(p==t)
            if(T.substr(s,m)==P){
                SetConsoleTextAttribute(hConsole, 2);
                cout<<"Pattern found at shift "<<s<<"\n";
            }else{
                spuriousHit++;
                SetConsoleTextAttribute(hConsole, 4);
                cout<<"Spurious Hit at "<<s<<"\n";
            }
        t=((t-h*charToInt(T[s]))*d+charToInt(T[s+m]))%q;
        if(t<0) t+=q;
    }
    SetConsoleTextAttribute(hConsole, 7);

}

int main()
{
    string T,P;
    cout<<"Enter Text and Pattern\n";
    cin>>T>>P;
    // T="31415";
    // P="31";
    int q=13;
    int d=10;
    KMP(T,P,d,q);
}