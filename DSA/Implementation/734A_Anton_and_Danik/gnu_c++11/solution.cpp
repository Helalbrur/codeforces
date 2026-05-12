// Anton and Danik (CF 734A)
// Rating  : 800
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-11-15
// Attempt : #1
// URL     : https://codeforces.com/contest/734/problem/A

#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int n;
    string helal;
    cin>>n;
    cin>>helal;
    int a=0,d=0;
    for(int i=0;i<helal.length();i++)
    {
        if(helal[i]=='A')
            a++;
        else
            d++;
    }
    if(a==d)
        cout<<"Friendship"<<endl;
    else if(a>d)
        cout<<"Anton"<<endl;
    else
        cout<<"Danik"<<endl;
}