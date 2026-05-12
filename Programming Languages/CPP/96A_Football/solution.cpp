// Football (CF 96A)
// Rating  : 900
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2017-01-03
// Attempt : #1
// URL     : https://codeforces.com/contest/96/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string  text;
    cin>>text;
    int flag=0,cone=0,czero=0;
    for(int i=0;i<text.length();i++)
    {
        if(cone>=7 ||czero>=7)
        {
            flag=1;
            break;
        }
        if(text[i]=='0')
        {
            czero++;
            cone=0;
        }
        else {
            cone++;
            czero=0;
        }
    }
    if(flag==1 ||cone>=7 ||czero>=7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}