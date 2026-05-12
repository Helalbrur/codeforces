// Game With Sticks (CF 451A)
// Rating  : 900
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/451/problem/A

#include<bits/stdc++.h>
using namespace std;
 int main()
{
     int n,m;
    cin>>n>>m;
    if(min(n,m)%2==0)
    {
        cout<<"Malvika"<<endl;
    }
    else
    {
        cout<<"Akshat"<<endl;
    }
 }