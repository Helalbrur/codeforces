// Nearly Lucky Number (CF 110A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-21
// Attempt : #1
// URL     : https://codeforces.com/contest/110/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
     string text;
    int count=0;
    cin>>text;
    for(int i=0;i<text.length();i++)
    {
        if(text[i]=='4'||text[i]=='7')
            count++;
    }
    if(count==4||count==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}