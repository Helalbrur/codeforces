// Lucky Division (CF 122A)
// Rating  : 1000
// Tags    : brute force, number theory
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/122/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
     char num[1007];
    cin>>num;
    int flag=0;
    for(int i=0;i<strlen(num);i++)
    {
        if(num[i]=='4'||num[i]=='7')
            continue;
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"YES"<<endl;
    else
    {
        int n;
        n=atoi(num);
        if(n%4==0 || n%7==0 ||n%44==0 ||n%47==0 ||n%74==0 ||n%77==0)
            cout<<"YES"<<endl;
         else
        {
            cout<<"NO"<<endl;
        }
     }
 }