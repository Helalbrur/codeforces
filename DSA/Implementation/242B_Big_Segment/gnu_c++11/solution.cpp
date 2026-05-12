// Big Segment (CF 242B)
// Rating  : 1100
// Tags    : implementation, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-07
// Attempt : #1
// URL     : https://codeforces.com/contest/242/problem/B

#include<bits/stdc++.h>
using namespace std;
#define infinity 10000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
int main()
{
    ll n;
    //freopen("149b.txt","r+",stdin);
    ll mx=0,mn=infinity;
    cin>>n;
    map<ii,ll> mp;
    for(ll i=1;i<=n;i++)
    {
        ll x,y;
        cin>>x>>y;
        mx=max(mx,max(x,y));
        mn=min(mn,min(x,y));
        mp[ii(min(x,y),max(x,y))]=i;
    }
    if(mp.find(ii(mn,mx))==mp.end())
        cout<<"-1"<<endl;
    else
        cout<<mp.at(ii(mn,mx))<<endl;
}