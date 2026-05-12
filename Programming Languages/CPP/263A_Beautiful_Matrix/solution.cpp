// Beautiful Matrix (CF 263A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-20
// Attempt : #1
// URL     : https://codeforces.com/contest/263/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int > ii;
int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};
int row=5;
int col=5;
int a[6][6];
int x,y;
int vis[6][6],d[6][6];
int BFS()
{
    memset(vis,0,sizeof vis);
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
            d[i][j]=99999;
    }
     d[x][y]=0;
    vis[x][y]=1;
    queue<ii> pq;
    pq.push(ii(x,y));
    while(!pq.empty())
    {
        ii t=pq.front();
        pq.pop();
        int u=t.first;
        int v=t.second;
        if(u==3 && v==3)
            return d[3][3];
        for(int i=0;i<4;i++)
        {
            int ux=u+fx[i];
            int vy=v+fy[i];
            if(!vis[ux][vy])
            {
                if(d[ux][vy]>d[u][v]+1)
                {
                    d[ux][vy]=d[u][v]+1;
                    pq.push(ii(ux,vy));
                }
                vis[ux][vy]=1;
            }
        }
    }
    return d[3][3];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("161A.txt","r+",stdin);
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>a[i][j];
            if(a[i][j])
            {
                x=i,y=j;
            }
        }
    }
    cout<<BFS()<<endl;
}