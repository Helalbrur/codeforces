// T-primes (CF 230B)
// Rating  : 1300
// Tags    : binary search, implementation, math, number theory
// Lang    : GNU C++11
// Solved  : 2016-12-25
// Attempt : #1
// URL     : https://codeforces.com/contest/230/problem/B

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set < ll > tPrime;
bool isPrime(ll n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    //freopen("142B.txt","r+",stdin);
    tPrime.insert(4);
    for(ll i=3;i<=1000000;i+=2)
    {
        if(isPrime(i))
            tPrime.insert(i*i);
    }
    ll n;
    cin>>n;
    while(n--)
    {
        ll a;
        cin>>a;
        if(tPrime.find(a)==tPrime.end())
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
}