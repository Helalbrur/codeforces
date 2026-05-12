// Counterexample  (CF 483A)
// Rating  : 1100
// Tags    : brute force, implementation, math, number theory
// Lang    : GNU C++11
// Solved  : 2017-02-06
// Attempt : #1
// URL     : https://codeforces.com/contest/483/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    for(ll i=a;i<=b;i++)
    {
        for(ll j=i+1;j<=b;j++)
        {
            for(ll k=j+1;k<=b;k++)
            {
                if(__gcd(i,j)==1 && __gcd(j,k)==1 && __gcd(i,k)!=1)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"-1"<<endl;
}