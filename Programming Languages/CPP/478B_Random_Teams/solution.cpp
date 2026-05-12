// Random Teams (CF 478B)
// Rating  : 1300
// Tags    : combinatorics, constructive algorithms, greedy, math
// Lang    : GNU C++11
// Solved  : 2017-02-09
// Attempt : #1
// URL     : https://codeforces.com/contest/478/problem/B

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nC2(ll n)
{
    return (n*(n-1))/2;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll s=n-m+1;
    cout<<(n%m)*nC2(n/m+1)+(m-(n%m))*nC2(n/m)<<" "<<nC2(s)<<endl;
 }