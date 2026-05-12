// Weird Rounding (CF 779B)
// Rating  : 1100
// Tags    : brute force, greedy
// Lang    : GNU C++11
// Solved  : 2017-02-26
// Attempt : #1
// URL     : https://codeforces.com/contest/779/problem/B

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll k;
    string n;
    cin>>n>>k;
    ll zero=0,nzero=0;
    for(int i=n.length()-1;i>=0;i--)
    {
        if(n[i]=='0')
            zero++;
        else
            nzero++;
        if(zero==k)
        {
            cout<<nzero<<endl;
            return 0;
        }
    }
    cout<<n.length()-1<<endl;
}