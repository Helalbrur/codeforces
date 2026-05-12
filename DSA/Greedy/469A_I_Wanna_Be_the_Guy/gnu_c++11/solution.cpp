// I Wanna Be the Guy (CF 469A)
// Rating  : 800
// Tags    : greedy, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/469/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,m;
    cin>>n;
    int a[n+3];
    memset(a,0,sizeof a);
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        int b;
        cin>>b;
        a[b]=1;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int b;
        cin>>b;
        a[b]=1;
    }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(!a[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"Oh, my keyboard!"<<endl;
    else
        cout<<"I become the guy."<<endl;
}