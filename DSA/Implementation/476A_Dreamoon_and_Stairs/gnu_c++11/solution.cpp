// Dreamoon and Stairs (CF 476A)
// Rating  : 1000
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2017-01-17
// Attempt : #1
// URL     : https://codeforces.com/contest/476/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int mn=n+5;
    if(m>n)
        cout<<-1<<endl;
    else
    {   int mul=m;
       for(int i=1;i<=n;i++){
        if(i*m*2>=n){
            cout<<i*m<<endl;
            return 0;
        }
         }
        cout<<-1<<endl;
    }
}