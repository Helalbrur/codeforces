// Cifera (CF 114A)
// Rating  : 1000
// Tags    : math
// Lang    : GNU C++11
// Solved  : 2017-02-13
// Attempt : #1
// URL     : https://codeforces.com/contest/114/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,n;
    cin>>a>>n;
    int cnt=0,s=a;
    for(ll i=a;i<=n;i*=a)
    {
          if(i==n)
        {
            cout<<"YES"<<endl;
            cout<<cnt<<endl;
            return 0;
        }
        cnt++;
    }
    if(n==a)
    {
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}