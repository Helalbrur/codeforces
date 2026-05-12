// One-dimensional Japanese Crossword (CF 721A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-09-30
// Attempt : #1
// URL     : https://codeforces.com/contest/721/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string name;
    cin>>n;
    cin>>name;
    int flag=0,count=0,c[100];
    for(int i=0;i<=n;i++)
        c[i]=0;
    for(int i=0;i<name.length();i++)
    {
        if(name[i]=='B')
        {
            if(flag==0)
            {
                count++;
                 flag=1;
            }
            c[count]++;
         }
        else{
            flag=0;
        }
     }
    cout<<count<<endl;
    for(int i=1;i<=count;i++)
    {
        cout<<c[i];
        if(i<count)
            cout<<" ";
    }
    cout<<endl;
    return 0;
}