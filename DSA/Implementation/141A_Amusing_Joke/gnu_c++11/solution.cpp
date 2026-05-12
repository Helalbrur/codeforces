// Amusing Joke (CF 141A)
// Rating  : 800
// Tags    : implementation, sortings, strings
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/141/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string guest,host,letter;
    //freopen("101.txt","r+",stdin);
    cin>>guest;
    cin>>host;
    cin>>letter;
    int a[27],b[27];
    int g=0,h=0,l=0;
    for(int i=0;i<26;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    while(g<guest.length() && h<host.length() && l<letter.length())
    {
        a[guest[g]-'A']++;
        a[host[h]-'A']++;
        b[letter[l]-'A']++;
        g++;
        h++;
        l++;
    }
    while(h<host.length())
    {
        a[host[h]-'A']++;
        h++;
    }
    while(g<guest.length())
    {
        a[guest[g]-'A']++;
        g++;
    }
    while(l<letter.length())
    {
        b[letter[l]-'A']++;
        l++;
    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
        //cout<<a[i]<<" "<<b[i]<<endl;
        if(a[i]!=b[i])
        {
            flag=1;
            break;
        }
    }
    if(flag ==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}