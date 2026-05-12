// Fox and Number Game (CF 389A)
// Rating  : 1000
// Tags    : greedy, math
// Lang    : GNU C++11
// Solved  : 2017-02-14
// Attempt : #1
// URL     : https://codeforces.com/contest/389/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5];
     for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s=a[0];
    for(int i=1;i<n;i++)
    {
        s=__gcd(s,a[i]);
    }
    cout<<s*n<<endl;
}