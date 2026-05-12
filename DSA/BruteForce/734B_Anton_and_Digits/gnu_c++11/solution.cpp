// Anton and Digits (CF 734B)
// Rating  : 800
// Tags    : brute force, greedy, implementation, math
// Lang    : GNU C++11
// Solved  : 2016-11-15
// Attempt : #1
// URL     : https://codeforces.com/contest/734/problem/B

#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int main()
{
    int a2,a3,a5,a6;
    cin>>a2>>a3>>a5>>a6;
    int m=min(a2,min(a6,a5));
    int sum=m*256;
    if(m<a2)
        sum=sum+min((a2-m),a3)*32;
    cout<<sum<<endl;
}