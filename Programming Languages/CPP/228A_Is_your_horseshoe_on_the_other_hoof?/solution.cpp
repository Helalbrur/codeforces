// Is your horseshoe on the other hoof? (CF 228A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/228/problem/A

#include<bits/stdc++.h>
using namespace std;
bool isEqual(int a,int b)
{
    return a==b;
}
bool notEqual(int a,int b)
{
    return a!=b;
}
int main()
{
    int a,b,c,d;
    //freopen("141.txt","r",stdin);
    cin>>a>>b>>c>>d;
    int count=0;
    if(a==b && c==d && a==d)
        count=3;
    else if(isEqual(a,b)&&isEqual(c,d)&& notEqual(b,c))
        count=2;
    else if(isEqual(a,c)&&isEqual(b,d)&& notEqual(b,c))
        count=2;
    else if(isEqual(a,d)&&isEqual(c,b)&& notEqual(a,c))
        count=2;
    else if(isEqual(a,b)&&isEqual(c,b)&& notEqual(a,d))
        count=2;
    else if(isEqual(a,b)&&isEqual(d,b)&& notEqual(a,c))
        count=2;
    else if(isEqual(a,d)&&isEqual(a,c)&& notEqual(a,b))
        count=2;
    else if(isEqual(c,b)&&isEqual(c,d)&& notEqual(a,d))
        count=2;
    else if(isEqual(a,b) || isEqual(a,c)||isEqual(a,d) ||isEqual(b,c) ||isEqual(b,d)||isEqual(c,d))
        count=1;
    cout<<count<<endl;
  }