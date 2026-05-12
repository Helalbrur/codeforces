// Shooting (CF 1216B)
// Rating  : 900
// Tags    : greedy, implementation, sortings
// Lang    : GNU C++11
// Solved  : 2019-09-21
// Attempt : #1
// URL     : https://codeforces.com/contest/1216/problem/B

#include<bits/stdc++.h>
using namespace std;
struct a{
    int p;
    int v;
};
int cmp(a p,a q)
{
    if(p.v>q.v)
        return true;
    return false;
}
int main()
{
   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    int n;
    cin>>n;
    a b[n+3];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b[i].p=i+1;
        b[i].v=x;
    }
    sort(b,b+n,cmp);
    long long sum=1;
    for(int i=0;i<n;i++){
                if(i>0){
            sum+=(i*b[i].v+1);
            //cout<<(i*b[i].v+1)<<endl;
        }
            }
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i].p<<" ";
    }
    cout<<endl;
  }