// Games (CF 268A)
// Rating  : 800
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/268/problem/A

#include<bits/stdc++.h>
using namespace std;
struct p{
    int h,q;
}a[35];
int main(){
     int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i].h=x;
        a[i].q=y;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             if(a[i].h==a[j].q)
                cnt++;
        }
    }
    cout<<cnt<<endl;
}