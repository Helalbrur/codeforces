// Football (CF 43A)
// Rating  : 1000
// Tags    : strings
// Lang    : GNU C++11
// Solved  : 2017-01-02
// Attempt : #1
// URL     : https://codeforces.com/contest/43/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string name;
    map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>name;
        mp[name]++;
    }
    int mx=0;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        if(it->second>mx)
        {
            mx=it->second;
            name=it->first;
        }
    }
    cout<<name<<endl;
}