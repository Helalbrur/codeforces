// Cheap Travel (CF 466A)
// Rating  : 1200
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/466/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int mn=n*a;
    mn=min(mn,(((n/m)*b)+((n-(n/m)*m)*a)));
    mn=min(mn,(n/m+1)*b);
    cout<<mn<<endl;
 }