// Ilya and Bank Account (CF 313A)
// Rating  : 900
// Tags    : implementation, number theory
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/313/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    if(n>=0)
        cout<<n<<endl;
    else
    {
        n=-n;
        if(n%10>=((n/10)%10))
        {
            n=n/10;
            if(n)
                cout<<"-"<<n<<endl;
            else
                cout<<n<<endl;
        }
        else
        {
            int r=n%10;
            n=n/100;
            if(n||r)
                cout<<"-";
            if(n)
                cout<<n;
            if(r||n)
                cout<<r<<endl;
            if(n==0&&r==0)
                cout<<0<<endl;
        }
    }
}