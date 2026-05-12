// Playing with Dice (CF 378A)
// Rating  : 800
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/378/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,f=0,d=0,s=0;
    cin>>a>>b;
    for(int i=1;i<7;i++)
    {
        if(abs(i-a)==abs(i-b))
            d++;
        else if(abs(i-a)<abs(i-b))
            f++;
        else
            s++;
    }
    cout<<f<<" "<<d<<" "<<s<<endl;
 }