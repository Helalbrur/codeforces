// k-th divisor (CF 762A)
// Rating  : 1400
// Tags    : math, number theory
// Lang    : GNU C++11
// Solved  : 2017-01-27
// Attempt : #2
// URL     : https://codeforces.com/contest/762/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> f;
    ll r=sqrt(n);
    for(int i=1;i<=r;i++)
    {
        if(n%i==0)
        {
                        if(r*r==n && r==i)
                f.push_back(i);
            else
            {
                f.push_back(i);
                 f.push_back(n/i);
            }
         }
    }
    if(k>f.size())
    {
        cout<<"-1"<<endl;
    }
    else
    {
        sort(f.begin(),f.end());
        cout<<f[k-1]<<endl;
    }
}