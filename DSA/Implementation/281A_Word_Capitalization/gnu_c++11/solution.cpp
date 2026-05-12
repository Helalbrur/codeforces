// Word Capitalization (CF 281A)
// Rating  : 800
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-12-21
// Attempt : #1
// URL     : https://codeforces.com/contest/281/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char text[10000];
    gets(text);
    for(int i=0;i<strlen(text);i++)
    {
        if(i==0)
            printf("%c",toupper(text[i]));
        else
            cout<<text[i];
    }
    cout<<endl;
}