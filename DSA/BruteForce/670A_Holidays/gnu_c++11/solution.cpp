// Holidays (CF 670A)
// Rating  : 900
// Tags    : brute force, constructive algorithms, greedy, math
// Lang    : GNU C++11
// Solved  : 2016-05-05
// Attempt : #1
// URL     : https://codeforces.com/contest/670/problem/A

#include<bits/stdc++.h>
using namespace std;
 int main()
{
   int n;
   cin>>n;
   int t=n;
   int min=0,max=0;
   while(t)
   {
      if(t>=7)
      {
          min=min+2;
      }
      if(t>=2)
      {
          max=max+2;
      }
      if(t==6)
      {
          min++;
      }
      if(t==1)
      {
          max=max+1;
      }
      t=t-7;
      if(t<0)
        break;
   }
     cout<<min <<" "<<max<<endl;
    return 0;
}