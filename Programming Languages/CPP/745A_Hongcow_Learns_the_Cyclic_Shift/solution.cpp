// Hongcow Learns the Cyclic Shift (CF 745A)
// Rating  : 900
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-12-18
// Attempt : #1
// URL     : https://codeforces.com/contest/745/problem/A

#include<bits/stdc++.h>
using namespace std;
#define mx 100
struct st{
    string s;
}data;
void chang(char str[])
{
    data.s=str;
    int l=strlen(str);
    str[0]=data.s[l-1];
    for(int i=1;i<l;i++)
    {
        str[i]=data.s[i-1];
    }
    return;
}
int main()
{
    char text[mx];
    cin>>text;
    int a=0;
    map <string, int> m;
    m.clear();
    for(int i=0;i<strlen(text);i++)
    {
        data.s=text;
        if(m.find(text)==m.end())
        {
            m[text]=a++;
        }
        chang(text);
        if(m.find(text)==m.end())
        {
            m[text]=a++;
        }
     }
    cout<<a<<endl;
}