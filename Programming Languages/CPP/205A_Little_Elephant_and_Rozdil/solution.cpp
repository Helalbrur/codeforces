// Little Elephant and Rozdil (CF 205A)
// Rating  : 900
// Tags    : brute force, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-01
// Attempt : #1
// URL     : https://codeforces.com/contest/205/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct point{
    ll x,c;
}p;
int main()
{
    ll n;
    cin>>n;
    ll mn=10000000000;
    ll pos=-1;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(mn>=x)
        {
            mn=x;
            pos=i;
            if(mp.find(x)==mp.end())
            {
                mp[x]=0;
            }
            else
            {
                ll t=mp.at(x);
                t++;
                mp[x]=t;
            }
        }
    }
    if(mp.at(mn)==0)
        cout<<pos+1<<endl;
    else
        cout<<"Still Rozdil"<<endl;
}