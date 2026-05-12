// Dijkstra? (CF 20C)
// Rating  : 1900
// Tags    : graphs, shortest paths
// Lang    : GNU C++11
// Solved  : 2016-12-09
// Attempt : #1
// URL     : https://codeforces.com/contest/20/problem/C

#include<bits/stdc++.h>
using namespace std;
#define mx 100004
//unsigned long long maxNumber std::numeric_limits<unsigned long long>::max();
typedef unsigned long long int ulli;
typedef pair < ulli,ulli > pii;
vector < pii > edge[mx];
ulli d[mx],p[mx];
ulli n,m;
void printPath(ulli u)
{
    if(u==1)
    {
        cout<<u;
        return;
    }
    printPath(p[u]);
    cout<<" "<<u;
}
ulli dijkstra(ulli b,ulli e)
{
    for(ulli i=0;i<n+2;i++)
    {
        d[i]=std::numeric_limits<unsigned long long>::max();
        //maxNumber;
    }
    d[b]=0;
    priority_queue< pii,vector < pii > , greater < pii > > pq;
    pq.push(pii(d[b],b));
    while(!pq.empty())
    {
        ulli u=pq.top().second;
        pq.pop();
        if(u==e)
            return d[e];
        for(ulli i=0;i<edge[u].size();i++)
        {
            ulli v=edge[u][i].first;
            ulli w=edge[u][i].second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(pii(d[v],v));
                p[v]=u;
            }
        }
    }
    return d[e];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("123.txt","r+",stdin);
    cin>>n>>m;
    for(ulli i=0;i<n+2;i++)
    {
        edge[i].clear();
    }
    for(ulli i=0;i<m;i++)
    {
        ulli a,b,w;
        cin>>a>>b>>w;
        edge[a].push_back(pii(b,w));
        edge[b].push_back(pii(a,w));
    }
    ulli dis=dijkstra(1,n);
    int x=-1;
    if(dis==std::numeric_limits<unsigned long long>::max())
        cout<<x<<endl;
    else{
        //cout<<dis<<endl;
        printPath(n);
        cout<<endl;
    }
 }