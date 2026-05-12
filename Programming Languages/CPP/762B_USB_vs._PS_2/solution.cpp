// USB vs. PS/2 (CF 762B)
// Rating  : 1400
// Tags    : greedy, implementation, sortings, two pointers
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/762/problem/B

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,string> ii;
int main()
{
    ll a,b,c;
    //freopen("123.txt","r+",stdin);
    cin>>a>>b>>c;
    ll m;
    cin>>m;
    vector<ii> v;
    for(ll i=0;i<m;i++)
    {
        ll x;
        string type;
        cin>>x>>type;
        v.push_back(ii(x,type));
    }
    sort(v.begin(),v.end());
    ll cost=0,cnt=0;
    for(ll i=0;i<m;i++)
    {
        if(v[i].second=="USB")
        {
            if(a)
            {
                cost+=v[i].first;
                cnt++;
                a--;
            }
            else if(c)
            {
                cost+=v[i].first;
                cnt++;
                c--;
            }
        }
        else
        {
            if(b)
            {
                cost+=v[i].first;
                cnt++;
                b--;
            }
            else if(c)
            {
                cost+=v[i].first;
                cnt++;
                c--;
            }
        }
    }
    cout<<cnt<<" "<<cost<<endl;
}