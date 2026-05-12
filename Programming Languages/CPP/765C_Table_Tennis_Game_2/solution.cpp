// Table Tennis Game 2 (CF 765C)
// Rating  : 1200
// Tags    : math
// Lang    : GNU C++11
// Solved  : 2017-02-14
// Attempt : #1
// URL     : https://codeforces.com/contest/765/problem/C

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  int k,a,b;
    cin>>k>>a>>b;
    long long int s=a/k+b/k;
    if(a/k==0 && b%k!=0)
        s=-1;
    if(b/k==0 && a%k!=0)
        s=-1;
    cout<<s<<endl;
}