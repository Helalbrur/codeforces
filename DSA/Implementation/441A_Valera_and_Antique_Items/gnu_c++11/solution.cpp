// Valera and Antique Items (CF 441A)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-25
// Attempt : #1
// URL     : https://codeforces.com/contest/441/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,v,mn=1000010;
    cin>>n>>v;
    priority_queue<int, vector<int> ,greater <int> > pq;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        mn=1000010;
        for(int j=0;j<k;j++)
        {
            int a;
            cin>>a;
            mn=min(mn,a);
        }
        if(mn<v)
            pq.push(i);
    }
    cout<<pq.size()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top();
        pq.pop();
        if(pq.size())
            cout<<" ";
    }
    cout<<endl;
}