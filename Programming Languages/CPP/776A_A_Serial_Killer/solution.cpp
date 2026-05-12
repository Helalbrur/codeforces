// A Serial Killer (CF 776A)
// Rating  : 900
// Tags    : brute force, implementation, strings
// Lang    : GNU C++11
// Solved  : 2017-02-23
// Attempt : #1
// URL     : https://codeforces.com/contest/776/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name1,name2;
    //freopen("aaaa.txt","r+",stdin);
    cin>>name1>>name2;
    int n;
    cin>>n;
    queue<string> q;
    cout<<name1<< " "<<name2<<endl;
    q.push(name1);
    q.push(name2);
    for(int i=1;i<=n;i++)
    {
         cin>>name1>>name2;
        string s1=q.front();
        q.pop();
        string s2=q.front();
        q.pop();
        if(s1==name1)
        {
            cout<<name2<< " "<<s2<<endl;
            q.push(name2);
            q.push(s2);
        }
        else
        {
            cout<<s1<<" "<<name2<<endl;
            q.push(s1);
            q.push(name2);
        }
     }
}