// Hotelier (CF 1200A)
// Rating  : 800
// Tags    : brute force, data structures, implementation
// Lang    : GNU C++11
// Solved  : 2019-08-18
// Attempt : #1
// URL     : https://codeforces.com/contest/1200/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("a.txt","r+",stdin);
    int n;
    cin>>n;
    string a;
    cin>>a;
    int l=0,r=n-1;
    int v[13];
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++){
        if(a[i]=='L'){
            for(int j=0;j<10;j++){
                if(v[j]==0){
                    v[j]=1;
                    //cout<<j<<endl;
                    break;
                }
            }
        }else if(a[i]=='R'){
            for(int j=9;j>=0;j--){
                if(v[j]==0){
                    v[j]=1;
                     //cout<<j<<endl;
                    break;
                }
            }
        }else{
            v[a[i]-'0']=0;
             //cout<<i<<endl;
        }
    }
    for(int i=0;i<10;i++){
        cout<<v[i];
    }
    cout<<endl;
}