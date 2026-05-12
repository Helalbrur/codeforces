// TL (CF 350A)
// Rating  : 1200
// Tags    : brute force, greedy, implementation
// Lang    : GNU C++11
// Solved  : 2017-02-09
// Attempt : #1
// URL     : https://codeforces.com/contest/350/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,mn=1000,mx=0,mnn=1000;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        mx=max(mx,a);
        mn=min(mn,a);
    }
    for(int i=0;i<m;i++)
    {
        cin>>a;
        mnn=min(mnn,a);
    }
    if(mnn>mx && mn*2<=mx && mx>0)
    {
        cout<<mx<<endl;
        return 0;
    }
    if(mnn>mx && mn*2<mnn&& mn>0)
     {
         cout<<2*mn<<endl;
        return 0;
     }
     if(mnn>2*mx && mn*2<=2*mx && mx>0)
     {
         cout<<2*mx<<endl;
        return 0;
     }
    cout<<"-1"<<endl;
}