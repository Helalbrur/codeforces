// IQ test (CF 25A)
// Rating  : 1300
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2017-01-19
// Attempt : #1
// URL     : https://codeforces.com/contest/25/problem/A

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
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(abs(a[i]-a[j])%2==1)
                cnt++;
        }
        if(cnt>=n-1)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
}