// Even Odds (CF 318A)
// Rating  : 900
// Tags    : math
// Lang    : GNU C++11
// Solved  : 2017-01-01
// Attempt : #1
// URL     : https://codeforces.com/contest/318/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
map<ll,ll> m;
vector<ll> vec;
int main()
{
    ll n,k;
    //freopen("188.txt","r+",stdin);
    cin>>n>>k;
    if(n%2==0)
    {
        ll a=n/2;
        if(k<=a)
            cout<<k*2-1<<endl;
        else
            cout<<k*2-n<<endl;
    }
    else
    {
        ll a=n/2;
        a++;
        if(k<=a)
            cout<<k*2-1<<endl;
        else
            cout<<k*2-n-1<<endl;
    }
}