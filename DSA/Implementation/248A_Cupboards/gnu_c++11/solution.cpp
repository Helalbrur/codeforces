// Cupboards (CF 248A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/248/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int r=0,l=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==0)
            l++;
        if(y==0)
            r++;
    }
     cout<<min(l,(n-l))+min(r,(n-r))<<endl;
  }