// Panoramix's Prediction (CF 80A)
// Rating  : 800
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2016-12-22
// Attempt : #1
// URL     : https://codeforces.com/contest/80/problem/A

#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int i=3;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    if(isPrime(m))
    {
        int flag=0;
        for(int i=n+1;i<m;i++)
        {
            if(isPrime(i))
            {
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}