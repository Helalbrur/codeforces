// k-th divisor (CF 762A)
// Rating  : 1400
// Tags    : math, number theory
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/762/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k;
    cin>>n>>k;
   priority_queue<ll,vector<ll> ,greater<ll> > pq;
   ll sq=sqrt(n);
    for(int i=1;i<=sq;i++)
    {
        if(n%i==0)
        {
            ll r=sqrt(n);
            if(r*r==n && r==i)
                pq.push(i);
            else
            {
                pq.push(i);
                pq.push(n/i);
            }
         }
    }
    if(pq.size()<k)
        cout<<"-1"<<endl;
    else
    {
        ll cnt=1;
    while(!pq.empty())
    {
        if(cnt==k)
            cout<<pq.top()<<endl;
        pq.pop();
        cnt++;
    }
    }
}