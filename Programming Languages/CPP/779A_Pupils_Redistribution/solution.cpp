// Pupils Redistribution (CF 779A)
// Rating  : 1000
// Tags    : constructive algorithms, math
// Lang    : GNU C++11
// Solved  : 2017-02-26
// Attempt : #1
// URL     : https://codeforces.com/contest/779/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //freopen("in.txt","r+",stdin);
    cin>>n;
    int a[10];
    int b[10];
    int c[10];
    int t;
    for(int i=1;i<=7;i++)
    {
        a[i]=0;
        b[i]=0;
        c[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        a[t]++;
        c[t]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        b[t]++;
        c[t]++;
    }
    for(int i=1;i<=5;i++)
    {
        //cout<<a[i]<<" "<< b[i]<<" "<<c[i]<< endl;;
        if(c[i]%2!=0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
   // cout<<endl;
    int cnt=0;
    for(int i=1;i<=5;i++)
    {
        if(a[i]>=0 && b[i]>=0)
        {
            cnt+=abs(a[i]-b[i])/2;
        }
    }
    cout<<cnt/2<<endl;
}