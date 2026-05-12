// Arrival of the General (CF 144A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-22
// Attempt : #1
// URL     : https://codeforces.com/contest/144/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mx=0,mx_p=-1,mn_p=-1,mn=9999999;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a>mx)
        {
            mx=a;
            mx_p=i;
        }
        if(mn>=a)
        {
            mn=a;
            mn_p=i;
        }
    }
    if(mn_p<mx_p)
        cout<<(mx_p)+(n-2-mn_p)<<endl;
    else
        cout<<(mx_p)+(n-1-mn_p)<<endl;
 }