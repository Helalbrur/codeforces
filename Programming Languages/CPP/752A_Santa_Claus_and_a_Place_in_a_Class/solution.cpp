// Santa Claus and a Place in a Class (CF 752A)
// Rating  : 800
// Tags    : constructive algorithms, math
// Lang    : GNU C++11
// Solved  : 2016-12-25
// Attempt : #1
// URL     : https://codeforces.com/contest/752/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int r,x,d;
    if(k%(m*2)==0)
    {
        r=k/(m*2);
        x=k-(m*2);
         d=m;
    }
    else{
        r=k/(m*2)+1;
        x=k-(m*2);
        d=(k%(m*2));
        if(d%2==0)
            d=d/2;
        else
        d=d/2+1;
    }
    char c;
    if(x%2==0)
    {
         c='R';
    }
    else{
        c='L';
     }
     cout<<r<<" "<<d<<" "<<c<<endl;
}