// Contest (CF 501A)
// Rating  : 900
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-02-08
// Attempt : #1
// URL     : https://codeforces.com/contest/501/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int misha=max(((a*3)/10),(a-(a/250)*c));
    int vasya=max(((b*3)/10),(b-(b/250)*d));
    if(misha>vasya)
    {
        cout<<"Misha"<<endl;
    }
    else if(vasya>misha)
    {
        cout<<"Vasya"<<endl;
    }
    else
    {
        cout<<"Tie"<<endl;
    }
}