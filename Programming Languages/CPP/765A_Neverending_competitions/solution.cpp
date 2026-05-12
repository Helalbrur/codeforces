// Neverending competitions (CF 765A)
// Rating  : 900
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2017-02-14
// Attempt : #1
// URL     : https://codeforces.com/contest/765/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //freopen("1.txt","r+",stdin);
    cin>>n;
    string home,s;
    cin>>home;
    int h=0,c=0;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s.substr(0,3)==home)
            h++;
        if(s.substr(5)==home)
            c++;
     }
    if(c==h)
    {
            cout<<"home"<<endl;
            return 0;
    }
    cout<<"contest"<<endl;
}