// Valera and X (CF 404A)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-02-06
// Attempt : #1
// URL     : https://codeforces.com/contest/404/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //freopen("in.txt","r+",stdin);
    cin>>n;
    char text[n+5][n+5];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>text[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j )
            {
                if(text[i][j]!=text[0][0]){
                                        cout<<"NO"<<endl;
                    return 0;
                }
            }
            else if(j==n-i-1  ) 
            {
                if(text[i][j]!=text[0][0])
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }   
            else if( (text[i][j]!=text[0][1])||(text[i][j]==text[0][0]))
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}