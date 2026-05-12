// Puzzles (CF 337A)
// Rating  : 900
// Tags    : greedy
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/337/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m+3];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    int mn=1111;
    for(int i=0;i+n-1<m;i++)
    {
         mn=min(mn,abs(a[i]-a[i+n-1]));
    }
    cout<<mn<<endl;
}