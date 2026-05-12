// Drinks (CF 200B)
// Rating  : 800
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2016-12-22
// Attempt : #1
// URL     : https://codeforces.com/contest/200/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double total=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        double a;
        cin>>a;
        total+=a;
    }
    cout<<setprecision(12)<<fixed<<total/(double)n<< endl;
 }