// Parallelepiped (CF 224A)
// Rating  : 1100
// Tags    : brute force, geometry, math
// Lang    : GNU C++11
// Solved  : 2017-02-19
// Attempt : #1
// URL     : https://codeforces.com/contest/224/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=sqrt(a*b/c);
    int y=sqrt(a*c/b);
    int z=sqrt(c*b/a);
    cout<<4*(x+y+z)<<endl;
}