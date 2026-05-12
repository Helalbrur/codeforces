// Marks (CF 152A)
// Rating  : 900
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-02-09
// Attempt : #1
// URL     : https://codeforces.com/contest/152/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char text[n+4][m+4];
    int mark[m+4];
    memset(mark,0,sizeof mark);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>text[i][j];
            mark[j]=max(mark[j],text[i][j]-'0');
        }
    }
    set<int> s;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mark[i]==text[j][i]-'0')
                s.insert(j);
        }
    }
    cout<<s.size()<<endl;
}