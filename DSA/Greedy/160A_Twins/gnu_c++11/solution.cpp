// Twins (CF 160A)
// Rating  : 900
// Tags    : greedy, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/160/problem/A

#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin>>n;
    int a[n+2];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n,cmp);
    int mx=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        mx+=a[i];
        sum-=a[i];
        cnt++;
        if(mx>sum)
            break;
     }
    cout<<cnt<<endl;
}