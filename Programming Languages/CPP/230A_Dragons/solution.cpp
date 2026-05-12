// Dragons (CF 230A)
// Rating  : 1000
// Tags    : greedy, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-03
// Attempt : #1
// URL     : https://codeforces.com/contest/230/problem/A

#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
}p[10000];
bool cmp(point a,point b)
{
    return a.x<b.x;
}
int main()
{
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    sort(p,p+n,cmp);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].x>=s)
        {
            flag=1;
            break;
        }
        else
        {
            s+=p[i].y;
        }
    }
    if(flag==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}