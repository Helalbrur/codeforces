// PolandBall and Hypothesis (CF 755A)
// Rating  : 800
// Tags    : brute force, graphs, math, number theory
// Lang    : GNU C++11
// Solved  : 2017-01-15
// Attempt : #1
// URL     : https://codeforces.com/contest/755/problem/A

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
    for(int i=3;i*i<=n;i+=2)
    if(n%i==0)
    return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    if(n==1)
        cout<<3<<endl;
    else if(n==2)
        cout<<4<<endl;
    else
    {
     for(int i=1;i<=n;i++)
    {
        if(!isPrime(n*i+1))
        {
            cout<<i<<endl;
            break;
        }
     }
    }
}