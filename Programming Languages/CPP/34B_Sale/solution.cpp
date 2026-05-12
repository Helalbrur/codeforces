// Sale (CF 34B)
// Rating  : 900
// Tags    : greedy, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-02
// Attempt : #1
// URL     : https://codeforces.com/contest/34/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+4];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]<0)
            sum+=a[i];
    }
    cout<<abs(sum)<<endl;
}