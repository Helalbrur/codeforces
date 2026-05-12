// Business trip (CF 149A)
// Rating  : 900
// Tags    : greedy, implementation, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-02
// Attempt : #1
// URL     : https://codeforces.com/contest/149/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[13];
    for(int i=0;i<12;i++)
    {
        cin>>a[i];
    }
    sort(a,a+12);
    int day=0;
    int cnt=0;
    for(int i=11;i>=0;i--)
    {
        if(day>=n)
        {
            break;
        }
        day+=a[i];
        cnt++;
    }
    if(cnt==12 && n>day)
        cout<<"-1"<<endl;
    else
    cout<<cnt<<endl;
}