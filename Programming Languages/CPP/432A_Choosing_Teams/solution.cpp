// Choosing Teams (CF 432A)
// Rating  : 800
// Tags    : greedy, implementation, sortings
// Lang    : GNU C++11
// Solved  : 2017-01-21
// Attempt : #1
// URL     : https://codeforces.com/contest/432/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
         if((i+1)%3==0)
        {
            if((5-a[i])>=k)
            {
                cnt++;
             }
        }
     }
    cout<<cnt<<endl;
}