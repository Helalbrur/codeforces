// Sherlock and his girlfriend (CF 776B)
// Rating  : 1200
// Tags    : constructive algorithms, number theory
// Lang    : GNU C++11
// Solved  : 2017-02-23
// Attempt : #1
// URL     : https://codeforces.com/contest/776/problem/B

#include<bits/stdc++.h>
using namespace std;
int mark[100000+10];
void Prime(int n)
{
    int limit=sqrt(n+1);
    for(int i=4;i<=n;i+=2)
        mark[i]=1;
    for(int i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            if(i<=limit)
            {
                for(int j=i*i;j<=n;j+=i*2)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    Prime(n+3);
    int a[n+5];
    vector<int> v;
    int pi=0,np=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=i+1;
        if(mark[i+1]==0)
            v.push_back(i+1);
        int flag=0;
        for(int j=0;j<v.size();j++)
        {
            if(a[i]==v[j] )
            {
                continue;
            }
            else if(a[i]%v[j]==0)
            {
                flag=1;
                a[i]=2;
  pi++;
                break;
            }
         }
        if(flag==0)
            a[i]=1,np++;
    }
    if(n==1)
    {
        cout<<1<<endl<<1<<endl;
        return 0;
    }
 if(np>0 && pi>0)
      cout<<2<<endl;
 else
 cout<<1<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i>1)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
 }