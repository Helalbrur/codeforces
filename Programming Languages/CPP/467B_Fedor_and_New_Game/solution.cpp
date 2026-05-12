// Fedor and New Game (CF 467B)
// Rating  : 1100
// Tags    : bitmasks, brute force, constructive algorithms, implementation
// Lang    : GNU C++11
// Solved  : 2017-02-07
// Attempt : #1
// URL     : https://codeforces.com/contest/467/problem/B

#include<bits/stdc++.h>
#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[m+5];
    for(int j=0;j<=m;j++)
    {
        cin>>a[j];
            }
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(__builtin_popcount(a[i]^a[m])<=k)
            cnt++;
    }
    cout<<cnt<<endl;
}