// Taymyr is calling you (CF 764A)
// Rating  : 800
// Tags    : brute force, implementation, math
// Lang    : GNU C++11
// Solved  : 2017-02-02
// Attempt : #1
// URL     : https://codeforces.com/contest/764/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,z,a=0,b=0,cnt=0;
    cin>>n>>m>>z;
    a=n,b=m;
    map<int ,int>mp;
    mp[a]++;
    while(a<=z)
    {
                a+=n;
        mp[a]++;
             }
    while(b<=z)
    {
                         if(mp.find(b)==mp.end())
        {
            b=b;
        }
        else
            cnt++;
        b+=m;
    }
    cout<<cnt<<endl;
}