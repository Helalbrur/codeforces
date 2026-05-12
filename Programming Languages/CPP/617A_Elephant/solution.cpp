// Elephant (CF 617A)
// Rating  : 800
// Tags    : math
// Lang    : GNU C++11
// Solved  : 2016-01-23
// Attempt : #1
// URL     : https://codeforces.com/contest/617/problem/A

#include<bits/stdc++.h>
using namespace std;
long int divid(long int x)
{
   long int sum=0;
   if(x%5==0)
   {
       sum=x/5;
   }
    else if(x>5)
    {
        sum=x/5;
        x=x-sum*5;
        if(x==4)
        {
           sum++;
         }
        else if(x==3)
        {
            sum++;
        }
        else if(x==2)
        {
            sum++;
        }
        else
        {
            sum++;
        }
     }
    else
        sum=1;
     return sum;
}
int main()
{
    long int x,sum;
    while(cin>>x)
    {
        cout<<divid(x)<<endl;
    }
    return 0;
}