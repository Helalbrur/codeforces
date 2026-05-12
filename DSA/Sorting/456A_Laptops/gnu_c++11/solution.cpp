// Laptops (CF 456A)
// Rating  : 1100
// Tags    : sortings
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/456/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    typedef pair <int,int> ii;
    vector<ii> v;
    for(int i=0;i<n;i++)
    {
        int p,q;
        cin>>p>>q;
        v.push_back(ii(p,q));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++)
    {
        if(v[i].second<v[i-1].second)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"Happy Alex"<<endl;
    else
        cout<<"Poor Alex"<<endl;
}