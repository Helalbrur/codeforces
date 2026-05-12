// Team (CF 231A)
// Rating  : 800
// Tags    : brute force, greedy
// Lang    : GNU C++11
// Solved  : 2016-12-24
// Attempt : #1
// URL     : https://codeforces.com/contest/231/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1 && a==c)
        {
            count++;
        }
        else if(b==a && b==1)
        {
            count++;
        }
        else if(1==c && c==b)
            count++;
    }
    cout<<count<<endl;
}