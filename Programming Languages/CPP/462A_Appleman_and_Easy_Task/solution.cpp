// Appleman and Easy Task (CF 462A)
// Rating  : 1000
// Tags    : brute force, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/462/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char text[n+5][n+5];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>text[i][j];
        }
    }
    int flag=0;
    int fx[]={1,0,-1,0};
    int fy[]={0,1,0,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int cnt=0;
            for(int k=0;k<4;k++)
            {
                int x=i+fx[k];
                int y=j+fy[k];
                if((x>=0&&x<n)&&(y>=0&&y<n)&&text[x][y]=='o')
                    cnt++;
            }
            if(cnt%2==1)
            {
                flag=1;
                break;
            }
         }
    }
    if(flag==1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}