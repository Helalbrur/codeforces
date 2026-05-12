// Mahmoud and Longest Uncommon Subsequence (CF 766A)
// Rating  : 1000
// Tags    : constructive algorithms, strings
// Lang    : GNU C++11
// Solved  : 2017-02-08
// Attempt : #1
// URL     : https://codeforces.com/contest/766/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int la=a.length(),lb=b.length();
    cout<<max(la,lb)<<endl;
    return 0;
  }