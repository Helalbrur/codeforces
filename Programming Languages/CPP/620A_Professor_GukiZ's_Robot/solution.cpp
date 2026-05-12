// Professor GukiZ's Robot (CF 620A)
// Rating  : 800
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2016-01-21
// Attempt : #1
// URL     : https://codeforces.com/contest/620/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x1,x2,y1,y2,d_x,d_y;
    while(cin>>x1>>y1>>x2>>y2)
    {
        d_x=fabs(x1-x2);
        d_y=fabs(y1-y2);
        if(d_x>=d_y)
        {
             cout<<d_y+d_x-d_y<<endl;
        }
        else
            cout<<d_x+d_y-d_x<<endl;
     }
}