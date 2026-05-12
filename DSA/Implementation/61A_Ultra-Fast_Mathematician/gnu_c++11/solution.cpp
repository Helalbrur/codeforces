// Ultra-Fast Mathematician (CF 61A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-22
// Attempt : #1
// URL     : https://codeforces.com/contest/61/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string first,second;
    cin>>first;
    cin>>second;
    for(int i=0;i<first.length();i++)
    {
        if(second[i]==first[i])
            cout<<0;
        else
            cout<<1;
    }
    cout<<endl;
}