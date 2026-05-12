// Effective Approach (CF 227B)
// Rating  : 1100
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-31
// Attempt : #1
// URL     : https://codeforces.com/contest/227/problem/B

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 int main()
{
    ll n;
    cin>>n;
    map<ll,ll> myMap;
    for(ll i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        myMap[a]=i;
    }
    ll q;
    cin>>q;
    ll v=0,p=0,temp=0;
    for(ll i=1;i<=q;i++)
    {
        ll a;
        cin>>a;
        temp=myMap.at(a);
        v+=temp;
        p+=n-temp+1;
    }
    cout<<v<<" "<<p<<endl;
}