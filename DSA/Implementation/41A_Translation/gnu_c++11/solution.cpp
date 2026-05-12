// Translation (CF 41A)
// Rating  : 800
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2017-01-01
// Attempt : #1
// URL     : https://codeforces.com/contest/41/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string decode,code;
    cin>>code;
    cin>>decode;
    if(code.length()==decode.length())
    {
        int len=code.length();
        int j=len-1;
        int i=0;
        int flag=0;
        while( i<len && j>=0)
        {
            if(code[i]!=decode[j])
            {
                flag=1;
                break;
            }
            i++;
            j--;
        }
        if(flag==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"NO"<<endl;
}