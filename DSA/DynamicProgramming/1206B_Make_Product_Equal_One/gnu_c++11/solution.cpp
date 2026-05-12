// Make Product Equal One (CF 1206B)
// Rating  : 900
// Tags    : dp, implementation
// Lang    : GNU C++11
// Solved  : 2019-08-19
// Attempt : #1
// URL     : https://codeforces.com/contest/1206/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("b.txt","r+",stdin);
    int n;
    cin>>n;
    int a[n+2];
    int64_t cnt=0;
    int m=0;
    int64_t p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            cnt+=a[i]-1;
                    }
        else if(a[i]==0){
            cnt++;
            p++;
        }else if(a[i]==-1){
            m++;
         }else if(a[i]<-1){
            m++;
            cnt+=abs(a[i])-1;
        }
        //cout<<cnt<<endl;
    }
     if(m%2==1){
        if(p==0)
            cnt+=2;
    }
    cout<<cnt<<endl;
  }