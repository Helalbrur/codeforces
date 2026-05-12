// Watching a movie (CF 499A)
// Rating  : 1000
// Tags    : greedy, implementation
// Lang    : GNU C++11
// Solved  : 2017-02-07
// Attempt : #1
// URL     : https://codeforces.com/contest/499/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int total=0;
    int s=1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        int cnt=0;
        while(s+x<=a)
        {
            s=s+x;
        }
        cnt=a-s;
        total+=cnt+b-a+1;
        s=b+1;
    }
    cout<<total<<endl;
}