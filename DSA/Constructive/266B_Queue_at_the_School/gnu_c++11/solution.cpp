// Queue at the School (CF 266B)
// Rating  : 800
// Tags    : constructive algorithms, graph matchings, implementation, shortest paths
// Lang    : GNU C++11
// Solved  : 2017-01-19
// Attempt : #1
// URL     : https://codeforces.com/contest/266/problem/B

#include<bits/stdc++.h>
using namespace std;
void swap(char *a, char *b)
{
    char p=*a;
    *a=*b;
    *b=p;
    return;
}
int main()
{
    int n,t;
    cin>>n>>t;
    string text;
    cin>>text;
    while(t--)
    {
        for(int i=0;i<n;i++)
        {
            if(text[i]=='B' && (i+1)<n && text[i+1]=='G')
            {
                swap(&text[i],&text[i+1]);
                i++;
            }
        }
    }
         cout<<text<<endl;
  }