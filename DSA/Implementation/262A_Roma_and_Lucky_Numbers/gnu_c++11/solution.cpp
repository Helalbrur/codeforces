// Roma and Lucky Numbers (CF 262A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-02-08
// Attempt : #1
// URL     : https://codeforces.com/contest/262/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cnt=0;
    cin>>n>>k;
    while(n--)
    {
        string t;
        cin>>t;
        int cn=0;
        int l=t.length();
        for(int i=0;i<l;i++)
        {
            if(t[i]=='7'||t[i]=='4')
                cn++;
        }
        if(cn<=k)
           cnt++; 
    }
    cout<<cnt<<endl;
}