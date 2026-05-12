// DZY Loves Chessboard (CF 445A)
// Rating  : 1200
// Tags    : dfs and similar, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-07
// Attempt : #1
// URL     : https://codeforces.com/contest/445/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    //freopen("254.txt","r+",stdin);
    cin>>n>>m;
    char text[n+2][m+2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>text[i][j];
            if(text[i][j]=='.')
            {
                if(i%2==0)
                {
                    if(j%2==1)
                        text[i][j]='B';
                    else
                        text[i][j]='W';
                }
                else{
                    if(j%2==0)
                        text[i][j]='B';
                    else
                        text[i][j]='W';
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<text[i][j];
        }
        cout<<endl;
    }
 }