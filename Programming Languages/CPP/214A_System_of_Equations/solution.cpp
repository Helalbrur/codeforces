// System of Equations (CF 214A)
// Rating  : 800
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2017-01-02
// Attempt : #1
// URL     : https://codeforces.com/contest/214/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<sqrt(n)+1;i++)
    {
        for(int j=0;j<sqrt(m)+1;j++)
        {
            if(((i*i)+j==n)&&((j*j)+i==m))
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}