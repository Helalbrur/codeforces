// Display Size (CF 747A)
// Rating  : 800
// Tags    : brute force, math
// Lang    : GNU C++11
// Solved  : 2016-12-19
// Attempt : #1
// URL     : https://codeforces.com/contest/747/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mn=100000000;
lli x,y;
void divisor(lli n)
{
    lli m=sqrt(n);
    for(int i=1;i<=m;i++)
    {
        if(n%i==0)
           {
                 if(mn>abs(i-n/i))
               {
                   mn=abs(i-n/i);
                   x=i;
                   y=n/i;
                   //cout<<mn<<" " <<x<<" " <<y<<endl;
               }
           }
    }
}
int main()
{
    lli n;
    cin>>n;
    divisor(n);
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
    x=0,y=0;
}