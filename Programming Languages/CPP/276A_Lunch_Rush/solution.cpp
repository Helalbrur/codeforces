// Lunch Rush (CF 276A)
// Rating  : 900
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/276/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int l;
int main()
{
    l n,k,mx=-1000000010,f,t;
    cin>>n>>k;
    for(l i=0;i<n;i++)
    {
        cin>>f>>t;
        if(k>=t)
            mx=max(mx,f);
        else
            mx=max(mx,(f-(t-k)));
    }
    cout<<mx<<endl;
}