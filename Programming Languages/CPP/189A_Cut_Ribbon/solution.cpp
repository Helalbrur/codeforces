// Cut Ribbon (CF 189A)
// Rating  : 1300
// Tags    : brute force, dp
// Lang    : GNU C++11
// Solved  : 2017-02-09
// Attempt : #1
// URL     : https://codeforces.com/contest/189/problem/A

#include <bits/stdc++.h>
using namespace std;
int n,dp[4005],a;
int main()
{
 fill(dp+1,dp+4005,-1e9);
 scanf("%d",&n);
 for(int j=1;j<=3;j++)
 {
  scanf("%d",&a);
  for(int i=a;i<=n;i++)
   dp[i]=max(dp[i-a]+1,dp[i]);
 }
printf("%d\n",dp[n]);
return 0;
}