// Borze (CF 32B)
// Rating  : 800
// Tags    : expression parsing, implementation
// Lang    : GNU C++11
// Solved  : 2016-12-21
// Attempt : #1
// URL     : https://codeforces.com/contest/32/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    int m=0,d=0;
    cin>>text;
    for(int i=0;i<text.length();i++)
    {
        if(text[i]=='.')
        {
            if(m==0)
                cout<<0;
            else
            {
                cout<<1;
                m=0;
            }
         }
        else if(text[i]=='-')
        {
            m++;
            if(m==1)
                continue;
            else
            {
                cout<<2;
                m=0;
            }
         }
    }
    cout<<endl;
}