// Watermelon (CF 4A)
// Rating  : 800
// Tags    : brute force, math
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/4/problem/A

#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int n;
    cin>>n;
    if(n<=2)
        cout<<"NO"<<endl;
    else if((n-2)%2==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}