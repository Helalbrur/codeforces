// Pashmak and Flowers (CF 459B)
// Rating  : 1300
// Tags    : combinatorics, implementation, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-07
// Attempt : #1
// URL     : https://codeforces.com/contest/459/problem/B

#include<bits/stdc++.h>
using namespace std;
#define infinity 10000000000
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll a[n+2];
    ll mn=infinity;
    ll mx=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>mx)
        {
            mx=a[i];
        }
        if(a[i]<mn)
        {
            mn=a[i];
        }
    }
    ll cmn=0,cmx=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==mn)
            cmn++;
        if(a[i]==mx)
            cmx++;
    }
    if(mx==mn)
    {
        if(cmx>2)
            cout<<0<<" "<<(ll)(cmx*((double)(cmx-1)/2))<<endl;
        else
            cout<<0<<" "<<1<<endl;
    }
    else
        cout<<mx-mn<<" "<<cmn*cmx<<endl;
}