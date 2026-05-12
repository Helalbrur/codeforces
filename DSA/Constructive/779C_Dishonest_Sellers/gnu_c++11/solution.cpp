// Dishonest Sellers (CF 779C)
// Rating  : 1200
// Tags    : constructive algorithms, greedy, sortings
// Lang    : GNU C++11
// Solved  : 2017-02-26
// Attempt : #1
// URL     : https://codeforces.com/contest/779/problem/C

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll cnt=0,cost=0;
    ii a[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].second;
    }
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        if(a[i].first>a[i].second)
            cost+=a[i].second,v.push_back(a[i].first-a[i].second);
        else{
            cost+=a[i].first;
            cnt++;
        }
    }
    if(cnt>=k)
    {
        cout<<cost<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    int i=0;
    //cout<<cost<<endl;
    while(cnt<k)
    {
         cnt++;
        cost+=v[i];
        i++;
    }
    cout<<cost<<endl;
}