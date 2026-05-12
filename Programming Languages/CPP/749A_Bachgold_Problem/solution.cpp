// Bachgold Problem (CF 749A)
// Rating  : 800
// Tags    : greedy, implementation, math, number theory
// Lang    : GNU C++11
// Solved  : 2016-12-19
// Attempt : #1
// URL     : https://codeforces.com/contest/749/problem/A

#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
 int main()
{
     int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<n/2<<endl;
        int l=n/2;
        for(int i=1;i<=l;i++)
        {
            if(i>1)
                cout<<" ";
            cout<<2;
        }
        cout<<endl;
    }
    else
    {
        int l=n/2;
        cout<<n/2<<endl;
        for(int i=1;i<=l-1;i++)
        {
             cout<<2<<" ";
        }
        cout<<3<<endl;
    }
}