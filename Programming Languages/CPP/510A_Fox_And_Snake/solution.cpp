// Fox And Snake (CF 510A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-19
// Attempt : #1
// URL     : https://codeforces.com/contest/510/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    bool left=true,right=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i%2==1)
            {
                cout<<"#";
            }
            else if(left==true)
            {
                if(j==m)
                    cout<<"#";
                else
                    cout<<".";
            }
            else if(right==true)
            {
                if(j==1)
                    cout<<"#";
                else
                    cout<<".";
             }
        }
        if(i%2==0)
        {
            if(left==true)
            {
                left=false;
                right=true;
            }
            else{
                left=true;
                right=false;
            }
        }
        cout<<endl;
    }
}