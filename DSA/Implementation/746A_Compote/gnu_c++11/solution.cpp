// Compote (CF 746A)
// Rating  : 800
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2016-12-18
// Attempt : #1
// URL     : https://codeforces.com/contest/746/problem/A

#include<bits/stdc++.h>
using namespace std;
#define mx 100
typedef long long int ll;
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll x=c/4;
    ll y=b/2;
    ll m=min(x,y);
    m=min(m,a);
    if(m==0||a==0)
        cout<<0<<endl;
    else
        cout<<m+m*2+m*4<<endl;
}