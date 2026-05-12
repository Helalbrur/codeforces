// Bit++ (CF 282A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-24
// Attempt : #1
// URL     : https://codeforces.com/contest/282/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    int n,c=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>text;
        if(text[0]=='+')
            ++c;
        else if(text[0]=='-')
            --c;
        else if(text[2]=='+')
            c++;
        else if(text[2]=='-')
            c--;
    }
    cout<<c<<endl;
}