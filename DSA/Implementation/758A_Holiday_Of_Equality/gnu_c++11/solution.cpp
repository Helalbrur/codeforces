// Holiday Of Equality (CF 758A)
// Rating  : 800
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2017-01-20
// Attempt : #1
// URL     : https://codeforces.com/contest/758/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    int mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<mx)
        {
            sum+=mx-a[i];
        }
    }
    cout<<sum<<endl;
}