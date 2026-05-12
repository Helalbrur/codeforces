// Beautiful Year (CF 271A)
// Rating  : 800
// Tags    : brute force
// Lang    : GNU C++11
// Solved  : 2016-12-21
// Attempt : #1
// URL     : https://codeforces.com/contest/271/problem/A

#include<bits/stdc++.h>
using namespace std;
bool isdiffer(int a,int b)
{
    if(a==b)
        return false;
    return true;
}
int main()
{
    int x;
    cin>>x;
    for(int i=x+1;i<=9013;i++)
    {
        int a=i%10;
        int b=(i/10)%10;
        int c=(i/100)%10;
        int d=(i/1000)%10;
        if(isdiffer(a,b)&&isdiffer(a,c)&&isdiffer(a,d)&&isdiffer(b,c)&&isdiffer(b,d)&&isdiffer(c,d))
        {
            cout<<i<<endl;
            break;
        }
    }
 }