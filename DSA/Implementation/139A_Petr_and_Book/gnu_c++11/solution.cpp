// Petr and Book (CF 139A)
// Rating  : 1000
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2016-12-31
// Attempt : #1
// URL     : https://codeforces.com/contest/139/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[8];
    queue<int>q;
    for(int i=1;i<=7;i++)
    {
        cin>>a[i];
        //q.push(a[i]);
    }
    int sum=0,pos=-1;
    q.push(n);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(pos!=-1)
            break;
        for(int i=1;i<8;i++)
        {
            n=n-a[i];
            if(n<=0)
            {
                pos=i;
                break;
            }
            q.push(n);
        }
    }
    cout<<pos<<endl;
}