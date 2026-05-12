// Gotta Catch Em' All! (CF 757A)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/757/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    //freopen("a.txt","r+",stdin);
    cin>>text;
    int b=0,B=0,l=0,s=0,a=0,u=0,r=0;
    for(int i=0;i<text.length();i++)
    {
        if(text[i]=='b')
            b++;
        else if(text[i]=='B')
            B++;
        else if(text[i]=='l')
            l++;
        else if(text[i]=='s')
            s++;
        else if(text[i]=='a')
            a++;
        else if(text[i]=='u')
            u++;
        else if(text[i]=='r')
            r++;
    }
    int mn=0;
    mn=min(B,l);
    mn=min(mn,s);
    mn=min(mn,r);
    mn=min(mn,b);
    int mx=min(a,u);
    if(mx>=2*mn)
    {
        cout<<mn<<endl;
    }
    else
    {
        cout<<mx/2<<endl;
    }
}