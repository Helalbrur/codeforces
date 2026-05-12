// Greg's Workout (CF 255A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-28
// Attempt : #1
// URL     : https://codeforces.com/contest/255/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    int cnt=0,one=0,two=0,three=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt++;
        if(cnt==1)
        {
            one+=a[i];
        }
        else if(cnt==2)
        {
            two+=a[i];
        }
        else{
            three+=a[i];
            cnt=0;
        }
    }
    if(one>=two)
    {
        if(three>=one)
        {
            cout<<"back"<<endl;
        }
        else
            cout<<"chest"<<endl;
    }
    else
    {
        if(three>two)
            cout<<"back"<<endl;
        else
            cout<<"biceps"<<endl;
    }
}