// New Year and Hurry (CF 750A)
// Rating  : 800
// Tags    : binary search, brute force, implementation, math
// Lang    : GNU C++11
// Solved  : 2016-12-30
// Attempt : #1
// URL     : https://codeforces.com/contest/750/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int t=240-k;
    int sum=0;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i*5;
        if(sum>t)
            break;
        count++;
    }
    cout<<count<<endl;
}