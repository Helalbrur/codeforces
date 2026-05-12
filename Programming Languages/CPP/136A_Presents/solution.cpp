// Presents (CF 136A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/136/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    int b[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int u=a[i]-1;
        int v=a[u]-1;
        if(b[v]==0)
        {
            b[v]=u+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i>0)
            cout<<" ";
        cout<<b[i];
    }
    cout<<endl;
}