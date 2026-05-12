// Team Olympiad (CF 490A)
// Rating  : 800
// Tags    : greedy, implementation, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-17
// Attempt : #1
// URL     : https://codeforces.com/contest/490/problem/A

#include<bits/stdc++.h>
using namespace std;
struct school{
    int o,t,th;
}group[10000];
int main()
{
    int n;
    cin>>n;
    int one=0,two=0,three=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            group[one++].o=i;
        }
        else if(a==2)
        {
            group[two++].t=i;
        }
        if(a==3)
        {
            group[three++].th=i;
        }
    }
    int mn=min(one,two);
    mn=min(mn,three);
    cout<<mn<<endl;
    for(int i=0;i<mn;i++)
    {
        cout<<group[i].o<<" "<<group[i].t<<" "<<group[i].th<<endl;
    }
}