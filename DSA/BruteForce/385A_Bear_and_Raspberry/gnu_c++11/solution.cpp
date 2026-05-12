// Bear and Raspberry (CF 385A)
// Rating  : 1000
// Tags    : brute force, greedy, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/385/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    int mx=0;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
        if(i>1)
        {
            if(mx<(a[i-1]-a[i]-c))
                mx=a[i-1]-a[i]-c;
        }
    }
    cout<<mx<<endl;
}