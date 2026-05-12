// Supercentral Point (CF 165A)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-31
// Attempt : #1
// URL     : https://codeforces.com/contest/165/problem/A

#include<bits/stdc++.h>
using namespace std;
#define mx 10000
typedef pair<int,int> ii;
typedef pair<ii,int> pii;
struct point{
    int x,y,p;
}data[mx];
int main()
{
    int n;
    cin>>n;
    queue<pii> q;
    for(int i=0;i<n;i++)
    {
        cin>>data[i].x>>data[i].y;
        data[i].p=i;
        q.push(pii(ii(data[i].x,data[i].y),i));
    }
    int cnt=0;
    while(!q.empty())
    {
        pii f=q.front();
        ii c=f.first;
        int pos=f.second;
        int l=0,r=0,lo=0,up=0;
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(i!=pos)
            {
                if(data[i].x>c.first && data[i].y==c.second)
                {
                    r++;
                }
                else if(data[i].x<c.first && data[i].y==c.second)
                {
                    l++;
                }
                else if(data[i].x==c.first && data[i].y>=c.second)
                {
                    up++;
                }
                else if(data[i].x==c.first && data[i].y<c.second)
                {
                    lo++;
                }
            }
        }
        if(lo>0 && r>0 && l>0 && up>0)
        {
            cnt++;
        }
    }
     cout<<cnt<<endl;
}