// Word (CF 59A)
// Rating  : 800
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-12-21
// Attempt : #1
// URL     : https://codeforces.com/contest/59/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char text[110];
    int u=0,l=0;
    cin>>text;
    for(int i=0;i<strlen(text);i++)
    {
        if(isupper(text[i]))
            u++;
        else
            l++;
    }
    if(u>l)
    {
        for(int i=0;i<strlen(text);i++)
            printf("%c",toupper(text[i]));
        cout<<endl;
    }
    else
    {
        for(int i=0;i<strlen(text);i++)
        {
            printf("%c",tolower(text[i]));
        }
        cout<<endl;
    }
 }