// Array (CF 300A)
// Rating  : 1100
// Tags    : brute force, constructive algorithms, implementation
// Lang    : GNU C++11
// Solved  : 2017-02-14
// Attempt : #1
// URL     : https://codeforces.com/contest/300/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a;
    vector<int> zero,pl,mn;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==0)
            zero.push_back(a);
        else if(a<0)
            mn.push_back(a);
        else
            pl.push_back(a);
    }
    if(pl.size())
    {
        if(mn.size()%2==0)
        {
            cout<<mn.size()-1;
            for(int i=1;i<mn.size();i++)
            {
                cout<<" "<<mn[i];
            }
            cout<<endl;
             cout<<pl.size();
            for(int i=0;i<pl.size();i++)
            {
                cout<<" "<<pl[i];
            }
            cout<<endl;
             cout<<zero.size()+1;
            cout<<" "<<mn[0];
            for(int i=0;i<zero.size();i++)
            {
                cout<<" "<<zero[i];
            }
            cout<<endl;
        }
        else{
            cout<<mn.size();
            for(int i=0;i<mn.size();i++)
            {
                cout<<" ";
                cout<<mn[i];
            }
            cout<<endl;
             cout<<pl.size();
            for(int i=0;i<pl.size();i++)
            {
                cout<<" ";
                cout<<pl[i];
            }
            cout<<endl;
             cout<<zero.size();
            for(int i=0;i<zero.size();i++)
            {
                    cout<<" ";
                cout<<zero[i];
            }
            cout<<endl;
        }
    }
    else
    {
        if(mn.size()%2==0)
        {
            cout<<mn.size()-3;
            for(int i=3;i<mn.size();i++)
            {
                    cout<<" ";
                cout<<mn[i];
            }
            cout<<endl;
             cout<<2;
            for(int i=0;i<2;i++)
            {
                    cout<<" ";
                cout<<mn[i];
            }
            cout<<endl;
             cout<<zero.size()+1;
            cout<<" "<<mn[2];
            for(int i=0;i<zero.size();i++)
            {
                cout<<" "<<zero[i];
            }
            cout<<endl;
        }
        else{
            cout<<mn.size()-2;
            for(int i=2;i<mn.size();i++)
            {
                    cout<<" ";
                cout<<mn[i];
            }
            cout<<endl;
             cout<<2;
            for(int i=0;i<2;i++)
            {
                    cout<<" ";
                cout<<mn[i];
            }
            cout<<endl;
             cout<<zero.size();
            for(int i=0;i<zero.size();i++)
            {
                    cout<<" ";
                cout<<zero[i];
            }
            cout<<endl;
        }
    }
}