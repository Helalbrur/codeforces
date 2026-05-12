// Cormen --- The Best Friend Of a Man (CF 732B)
// Rating  : 1000
// Tags    : dp, greedy
// Lang    : GNU C++11
// Solved  : 2016-10-19
// Attempt : #1
// URL     : https://codeforces.com/contest/732/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int array[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        if(k-array[i]>array[i+1])
        {
            count+=k-array[i+1]-array[i];
            array[i+1]=k-array[i];
        }
    }
    cout<<count<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
 }