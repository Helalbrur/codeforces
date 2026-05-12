// Snacktower (CF 767A)
// Rating  : 1100
// Tags    : data structures, implementation
// Lang    : GNU C++11
// Solved  : 2017-03-05
// Attempt : #1
// URL     : https://codeforces.com/contest/767/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    priority_queue<int> p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int tp=n;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==tp)
        {
            cout<<a[i];
            tp--;
            while(!p.empty())
            {
                if(p.top()==tp)
                {
                    cout<<" "<<p.top();
                    tp--;
                    p.pop();
                }
                else
                {
                    break;
                }
            }
            cout<<endl;
        }
        else
        {
            p.push(a[i]);
            cout<<endl;
        }
    }
}