// Expression (CF 479A)
// Rating  : 1000
// Tags    : brute force, math
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/479/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==1)
    {
        if(b==1)
        {
            if(c==1)
            {
                cout<<a+b+c<<endl;
            }
            else
                cout<<(a+b)*c<<endl;
        }
        else if(c==1)
        {
           cout<<a+b+c<<endl;
        }
        else
            cout<<max(((a+b)*c),(a+(b*c)))<<endl;
    }
    else if(b==1)
    {
        if(c==1)
        {
            cout<<max((a+b+c),(a*(b+c)))<<endl;
        }
        else
        {
            cout<<max(((a+b)*c),a*(b+c))<<endl;
        }
    }
    else
    {
        if(c==1)
        {
            cout<<max((a*b+c),(a*(b+c)))<<endl;
        }
        else
            cout<<a*b*c<<endl;
    }
}