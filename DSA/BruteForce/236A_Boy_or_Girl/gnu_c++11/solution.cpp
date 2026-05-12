// Boy or Girl (CF 236A)
// Rating  : 800
// Tags    : brute force, implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/236/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    int a[27];
    cin>>name;
    int c=0;
    for(int i=0;i<26;i++)
        a[i]=0;
    for(int i=0;i<name.length();i++)
    {
        a[name[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i])
            c++;
    }
    if(c%2==0)
        cout<<"CHAT WITH HER!"<<endl;
    else
        cout<<"IGNORE HIM!"<<endl;
}