// Choose Two Numbers (CF 1206A)
// Rating  : 800
// Tags    : math, sortings
// Lang    : GNU C++11
// Solved  : 2019-08-19
// Attempt : #1
// URL     : https://codeforces.com/contest/1206/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("a.txt","r+",stdin);
    int n;
    cin>>n;
    int a[n+2];
    int vis[402];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    int m;
    cin>>m;
    int b[m+2];
     for(int i=1;i<=m;i++){
        cin>>b[i];
        vis[b[i]]=1;
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[a[i]+b[j]]==0){
                cout<<a[i]<<" "<<b[j]<<endl;
                return 0;
            }
        }
    }
}