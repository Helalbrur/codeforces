// Perfect Permutation (CF 233A)
// Rating  : 800
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2017-02-07
// Attempt : #1
// URL     : https://codeforces.com/contest/233/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+3],b[n+3],j=0,x=0;
    if(n%2==1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i+=2)
        a[j++]=i;
    for(int k=2;k<=n;k+=2)
        b[x++]=k;
    for(int i=0;i<j;i++)
    {
        cout<<b[i]<<" "<<a[i];
        if(i<j-1)
            cout<<" ";
    }
    cout<<endl;
}