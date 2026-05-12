// Devu, the Singer and Churu, the Joker (CF 439A)
// Rating  : 900
// Tags    : greedy, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-19
// Attempt : #1
// URL     : https://codeforces.com/contest/439/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,sum=0,a;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }
    if(((n-1)*10+sum)>d)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<(d-sum)/5<<endl;
    }
}