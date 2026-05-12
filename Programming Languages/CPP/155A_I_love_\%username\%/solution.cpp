// I_love_\%username\% (CF 155A)
// Rating  : 800
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/155/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mx=0;
    int mn=100000;
    int c=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(i==0)
        {
            mx=a;
            mn=a;
        }
        else if(a>mx)
        {
            c++;
            mx=a;
        }
        else if(a<mn)
        {
            c++;
            mn=a;
        }
    }
    cout<<c<<endl;
}