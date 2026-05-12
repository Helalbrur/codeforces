// Dubstep (CF 208A)
// Rating  : 900
// Tags    : strings
// Lang    : GNU C++11
// Solved  : 2017-01-13
// Attempt : #1
// URL     : https://codeforces.com/contest/208/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string music;
    //freopen("130a.cpp","r+",stdin);
    cin>>music;
    int k=0;
    int len=music.length();
    char dubmusic[len+3];
    for(int i=0;i<len;i++)
    {
        if(i+2<len && (music[i]=='W' && music[i+1]=='U' && music[i+2]=='B'))
        {
            i+=2;
            if(k>0)
                dubmusic[k++]=' ';
        }
        else
        {
            dubmusic[k++]=music[i];
        }
     }
    dubmusic[k]='\0';
    cout<<dubmusic<<endl;
 }