// Tram (CF 116A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/116/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cap=0,mx=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cap-=a;
        cap+=b;
        if(cap>mx)
        {
            mx=cap;
        }
    }
    cout<<mx<<endl;
}