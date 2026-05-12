// Xenia and Ringroad (CF 339B)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-27
// Attempt : #1
// URL     : https://codeforces.com/contest/339/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int a,cnt=0,x=1;
    for(long long int i=0;i<m;i++)
    {
        cin>>a;
        if(x<a)
        {
            while(x<a)
            {
                x++,cnt++;
            }
        }
        else if(x>a)
        {
            while(x<=n)
            {
                x++,cnt++;
            }
            x=1;
            while(x<a)
            {
                x++,cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}