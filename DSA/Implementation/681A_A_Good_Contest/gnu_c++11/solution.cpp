// A Good Contest (CF 681A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-06-14
// Attempt : #1
// URL     : https://codeforces.com/contest/681/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string name;
    int before,after;
    cin>>n;
    int count=0;
    while(n--)
    {
        cin>>name>>before>>after;
        if(before>=2400 && after>before)
            count++;
    }
    if(count>0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}