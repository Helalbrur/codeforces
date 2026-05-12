// Jzzhu and Children (CF 450A)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-31
// Attempt : #1
// URL     : https://codeforces.com/contest/450/problem/A

#include<bits/stdc++.h>
#define mx 1000
using namespace std;
typedef pair<int ,int> ii;
int main()
{
    int n,m;
    cin>>n>>m;
    queue<ii> q;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        q.push(ii(a,i));
    }
    int pos=-1;
    while(!q.empty())
    {
        if(q.size()==1)
        {
            pos=q.front().second;
        }
        ii f=q.front();
        q.pop();
        if(f.first-m>0)
            q.push(ii((f.first-m),f.second));
    }
    cout<<pos<<endl;
}