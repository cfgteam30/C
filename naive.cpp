#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    string t,p;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cin>>t>>p;

    int n = t.length(), m = p.length();
    int i=0,j;
    int comp = 0;
    while(i<n-m+1)
    {
        j = 0;
        
        int loopComp = 0;
        while(j<m)
        {
            loopComp++;
            if(p[j]==t[i+j])
                j++;
            else
                break;   
        }
        if(j==m)
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout<<"Pattern found between "<<i<<" and "<<i+m-1<<"\n";
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"Comparisons "<<i<<":"<<loopComp<<"\n";
        comp+=loopComp;
        i++;
    }
    
    cout<<"Total number of comparisons "<<comp<<"\n";
    return 0;
}