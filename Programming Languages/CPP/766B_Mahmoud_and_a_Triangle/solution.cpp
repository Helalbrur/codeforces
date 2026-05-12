// Mahmoud and a Triangle (CF 766B)
// Rating  : 1000
// Tags    : constructive algorithms, geometry, greedy, math, number theory, sortings
// Lang    : GNU C++11
// Solved  : 2017-02-08
// Attempt : #1
// URL     : https://codeforces.com/contest/766/problem/B

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
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
                        if((a[i]+a[i+1]>a[i+2]) )
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
           }
    cout<<"NO"<<endl;
}