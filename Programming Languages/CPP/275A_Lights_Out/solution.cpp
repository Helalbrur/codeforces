// Lights Out (CF 275A)
// Rating  : 900
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-21
// Attempt : #1
// URL     : https://codeforces.com/contest/275/problem/A

#include<bits/stdc++.h>
using namespace std;
int row=3,col=3;
int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};
bool isValid(int x,int y)
{
    return (x>=0 && y>=0 &&x<row &&y<col);
}
int main()
{
    int a[3][3];
    int b[3][3];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }
    int i=0,j=0;
    for( i=0;i<row;i++)
    {
         for(j=0;j<col;j++)
        {
              int total=0;
            total+=a[i][j];
            for(int k=0;k<4;k++)
            {
                int x=i+fx[k];
                int y=j+fy[k];
                if(isValid(x,y))
                {
                    total+=a[x][y];
                }
            }
             if(total%2==0)
                cout<<1;
            else{
                cout<<0;
            }
        }
        cout<<endl;
     }
}