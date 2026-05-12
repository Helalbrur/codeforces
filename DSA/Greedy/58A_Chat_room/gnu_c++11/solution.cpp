// Chat room (CF 58A)
// Rating  : 1000
// Tags    : greedy, strings
// Lang    : GNU C++11
// Solved  : 2017-01-03
// Attempt : #1
// URL     : https://codeforces.com/contest/58/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
     char text[10000];
    //freopen("t.txt","r+",stdin);
    cin>>text;
    int h=0,e=0,l=0,l1=0,o=0,flag=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(h==1)
        {
            if(e==1)
            {
                if(l==1)
                {
                    if(l1==1)
                    {
                        if(o==1)
                        {
                            flag=1;
                            break;
                        }
                        else if(text[i]=='o')
                        {
                             o=1;
                             flag=1;
                             break;
                        }
                    }
                    else if(text[i]=='l')
                    {
                        l1=1;
                    }
                }
                else if(text[i]=='l')
                {
                    l=1;
                }
            }
            else if(text[i]=='e')
            {
                e=1;
            }
        }
        else if(text[i]=='h')
        {
            h=1;
        }
    }
    if(flag==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}