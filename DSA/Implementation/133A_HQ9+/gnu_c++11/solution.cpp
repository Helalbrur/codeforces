// HQ9+ (CF 133A)
// Rating  : 900
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-24
// Attempt : #1
// URL     : https://codeforces.com/contest/133/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char text[110];
    gets(text);
    int flag=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]=='H'||text[i]=='Q'||text[i]=='9')
        {
            cout<<"YES"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"NO"<<endl;
}