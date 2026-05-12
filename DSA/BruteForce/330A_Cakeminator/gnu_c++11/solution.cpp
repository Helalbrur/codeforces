// Cakeminator (CF 330A)
// Rating  : 800
// Tags    : brute force, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-24
// Attempt : #1
// URL     : https://codeforces.com/contest/330/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char text[n+5][m+5];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>text[i][j];
        }
    }
    int cr=0,cc=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(text[i][j]=='.')
                cnt++;
        }
        if(cnt==m)
            cr++;
    }
    for(int i=0;i<m;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(text[j][i]=='.')
                cnt++;
        }
        if(cnt==n)
            cc++;
    }
    //cout<<cr<<" "<<cc<<endl;
    if((n*cc+m*cr)>=cc*cr)
        cout<<(n*cc+m*cr)-cc*cr<<endl;
    else
       cout<<0<<endl;
}