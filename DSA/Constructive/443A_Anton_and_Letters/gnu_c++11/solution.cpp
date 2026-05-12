// Anton and Letters (CF 443A)
// Rating  : 800
// Tags    : constructive algorithms, implementation
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/443/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    //freopen("253a.txt","r+",stdin);
    getline(cin,text);
    map<char,int> mp;
    for(int i=0;i<text.length();i++)
    {
        if(isalpha(text[i]))
        {
            mp[text[i]]++;
        }
    }
    cout<<mp.size()<<endl;
}