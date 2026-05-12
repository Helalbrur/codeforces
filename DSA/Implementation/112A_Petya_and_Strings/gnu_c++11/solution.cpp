// Petya and Strings (CF 112A)
// Rating  : 800
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-12-24
// Attempt : #1
// URL     : https://codeforces.com/contest/112/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string first,second;
    cin>>first;
    cin>>second;
    int i=0,j=0;
    while(i<first.length() && j<second.length())
    {
        first[i]=tolower(first[i]);
        second[j]=tolower(second[j]);
        i++,j++;
    }
    while(i<first.length())
    {
        first[i]=tolower(first[i]);
        i++;
    }
    while(j<second.length())
    {
        second[j]=tolower(second[j]);
        j++;
    }
    if(first==second)
        cout<<0<<endl;
    else if(first>second)
        cout<<1<<endl;
    else
        cout<<"-1"<<endl;
}