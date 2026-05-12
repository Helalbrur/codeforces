// Arpa’s hard exam and Mehrdad’s naive cheat (CF 742A)
// Rating  : 1000
// Tags    : implementation, math, number theory
// Lang    : GNU C++11
// Solved  : 2016-12-06
// Attempt : #1
// URL     : https://codeforces.com/contest/742/problem/A

#include<bits/stdc++.h>
using namespace std;
 long long int BigMod(long long int a,long long int b,long long int m)
{
    if(b==0)
        return 1%m;
    long long int x=BigMod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)
    {
        x=(x*a)%m;
    }
    return x;
}
int main()
{
    long long int n,b=1378,m=10;
     cin>>n;
    cout<<BigMod(b,n,m)<<endl;
 }