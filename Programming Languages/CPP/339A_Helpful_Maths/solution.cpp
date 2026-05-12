// Helpful Maths (CF 339A)
// Rating  : 800
// Tags    : greedy, implementation, sortings, strings
// Lang    : GNU C++11
// Solved  : 2016-12-23
// Attempt : #1
// URL     : https://codeforces.com/contest/339/problem/A

#include<bits/stdc++.h>
using namespace std;
vector<int> sum;
int main()
{
    string text;
    cin>>text;
    for(int i=0;i<text.length();i++)
    {
        if(isdigit(text[i]))
        {
            sum.push_back(text[i]-'0');
        }
     }
    sort(sum.begin(),sum.end());
    for(int i=0;i<sum.size();i++)
    {
        if(i>0 && i<sum.size())
            cout<<"+";
        cout<<sum[i];
    }
    cout<<endl;
    sum.clear();
}