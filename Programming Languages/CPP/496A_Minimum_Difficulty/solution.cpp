// Minimum Difficulty (CF 496A)
// Rating  : 900
// Tags    : brute force, implementation, math
// Lang    : GNU C++11
// Solved  : 2017-01-28
// Attempt : #1
// URL     : https://codeforces.com/contest/496/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    int mx=0,mn=7888888;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
            mx=max(mx,a[i]-a[i-1]);
        if(i>1)
            mn=min(mn,a[i]-a[i-2]);
    }
    cout<<max(mn,mx)<<endl;
}