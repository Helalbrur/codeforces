// Oath of the Night's Watch (CF 768A)
// Rating  : 900
// Tags    : constructive algorithms, sortings
// Lang    : GNU C++11
// Solved  : 2017-02-20
// Attempt : #1
// URL     : https://codeforces.com/contest/768/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll> v;
    ll a,mx=0,mn=10000000000,cnt=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        mx=max(mx,a);
        mn=min(mn,a);
    }
    for(ll i=0;i<n;i++)
    {
        if(v[i]>mn && v[i]<mx)
            cnt++;
    }
    cout<<cnt<<endl;
}