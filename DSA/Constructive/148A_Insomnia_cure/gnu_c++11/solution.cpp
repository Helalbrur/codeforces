// Insomnia cure (CF 148A)
// Rating  : 800
// Tags    : constructive algorithms, implementation, math
// Lang    : GNU C++11
// Solved  : 2016-12-22
// Attempt : #1
// URL     : https://codeforces.com/contest/148/problem/A

#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    for(int i=1;i<=d;i++)
    {
        a[i]=1;
    }
    int k_i=k,l_i=l,m_i=m,n_i=n;
    while(k_i<=d && l_i<= d && m_i<=d && n_i<=d )
    {
        a[k_i]=0;
        a[l_i]=0;
        a[m_i]=0;
        a[n_i]=0;
        k_i+=k;
        l_i+=l;
        m_i+=m;
        n_i+=n;
     }
    while(k_i<=d)
    {
        a[k_i]=0;
        k_i+=k;
    }
    while(l_i<=d)
    {
        a[l_i]=0;
        l_i+=l;
    }
    while(m_i<=d)
    {
        a[m_i]=0;
        m_i+=m;
    }
    while(n_i<=d)
    {
        a[n_i]=0;
        n_i+=n;
    }
    int count=0;
    for(int i=1;i<=d;i++)
    {
        if(a[i])
            count++;
        //cout<<a[i]<<endl;
    }
    cout<<d-count<<endl;
}