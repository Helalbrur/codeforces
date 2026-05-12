// Domino (CF 353A)
// Rating  : 1200
// Tags    : implementation, math
// Lang    : GNU C++11
// Solved  : 2017-02-13
// Attempt : #1
// URL     : https://codeforces.com/contest/353/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n;
    //freopen("350.txt","r+",stdin);
    cin>>n;
    int s=0,ss=0,cnt=0,ca=0,cb=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        s+=a;
        ss+=b;
        if(a%2==1)
            ca++;
        if(b%2==1)
            cb++;
        if(a%2==b%2 && a%2==1)
            cnt++;
    }
    //cout<<s<<" "<<ss<<endl;
    //cout<<ca<<" "<<cb<<" "<<cnt<<endl;
    if(s%2==0 && ss%2==0)
    {
        cout<<0<<endl;
    }
    else if(s%2==1 && ss%2==1 && cnt<ca && cb>cnt &&ca%2==1 && cb%2==1)
    {
        cout<<"1"<<endl;
    }
    else if((s%2==1) && cb>cnt &&cb%2==1)
    {
        cout<<"1"<<endl;
    }
    else if(ss%2==1 && ca>cnt && ca%2==1)
    {
        cout<<"1"<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
}