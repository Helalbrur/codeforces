// Shell Game (CF 777A)
// Rating  : 1000
// Tags    : constructive algorithms, implementation, math
// Lang    : GNU C++11
// Solved  : 2017-03-01
// Attempt : #1
// URL     : https://codeforces.com/contest/777/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
    return;
}
int main()
{
    ll n,p;
    cin>>n>>p;
    int a[3];
    memset(a,0,sizeof a);
    a[p]=1;
    n=n%6;
    while(n)
    {
        if(n%2==0)
        {
            swap(&a[1],&a[2]);
        }
        else
        {
            swap(&a[1],&a[0]);
        }
        n--;
    }
    for(int i=0;i<3;i++)
    {
        if(a[i])
            cout<<i<<endl;
    }
 }