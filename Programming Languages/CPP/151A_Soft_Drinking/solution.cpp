// Soft Drinking (CF 151A)
// Rating  : 800
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/151/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int ml=(k*l)/(nl*n);
    int sl=p/(n*np);
    int s=(c*d)/n;
    cout<<min(min(ml,sl),s)<<endl;
}