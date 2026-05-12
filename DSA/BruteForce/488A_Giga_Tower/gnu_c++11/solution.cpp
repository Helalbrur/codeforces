// Giga Tower (CF 488A)
// Rating  : 1100
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2017-02-17
// Attempt : #1
// URL     : https://codeforces.com/contest/488/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool found(ll n)
{
    if(n<0)
        n=-n;
    while(n)
    {
        if(n%10==8)
            return true;
        n=n/10;
    }
    return false;
}
int main()
{
    ll n;
    cin>>n;
    ll cnt=0;
    bool flag=true;
    while(flag)
    {
        n++;
        cnt++;
        if(found(n))
        {
            flag=false;
        }
    }
    cout<<cnt<<endl;
}