// Timofey and cubes (CF 764B)
// Rating  : 900
// Tags    : constructive algorithms, implementation
// Lang    : GNU C++11
// Solved  : 2017-02-02
// Attempt : #1
// URL     : https://codeforces.com/contest/764/problem/B

#include<bits/stdc++.h>
using namespace std;
void swap(long long int *a,long long int *b)
{
    long long int t=*a;
    *a=*b;
    *b=t;
    return;
}
int main()
{
    long long int n,st=1;;
    cin>>n;
    long long int a[n+5],p[n+5];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long int i=1;
    while(i<=n-i+1)
    {
                p[i]=i;
        p[n-i+1]=i;
        i++;
    }
    for(long long int i=1;i<=n;i++)
    {
                if(p[i]%2==0)
            cout<<a[i];
        else
            cout<<a[n-i+1];
        if(i<n)
            cout<<" ";
    }
    cout<<endl;
}