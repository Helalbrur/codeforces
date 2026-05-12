// Way Too Long Words (CF 71A)
// Rating  : 800
// Tags    : strings
// Lang    : GNU C++11
// Solved  : 2015-10-09
// Attempt : #1
// URL     : https://codeforces.com/contest/71/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string helal;
    //freopen("input.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>helal;
        if(helal.length()>10)
        {
            cout<<helal[0]<<helal.length()-2<<helal[helal.length()-1]<<endl;
        }
        else
            cout<<helal<<endl;
    }
}