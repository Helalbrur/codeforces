// Pashmak and Garden (CF 459A)
// Rating  : 1200
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-01-14
// Attempt : #1
// URL     : https://codeforces.com/contest/459/problem/A

#include<bits/stdc++.h>
using namespace std;
bool isValid(int x1,int y1,int x2,int y2)
{
    if(x1==x2||y1==y2)
        return true;
    else if(abs(x1-x2)==abs(y1-y2))
        return true;
    return false;
}
int main()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(isValid(x1,y1,x2,y2))
    {
        if(x1==x2)
        {
            if(x1+abs(y1-y2)<=1000 && x1+abs(y1-y2)>=-1000)
                cout<<x1+abs(y1-y2)<<" "<<y1<<" "<<x1+abs(y1-y2)<<" "<<y2<<endl;
            else
                cout<<x1-abs(y1-y2)<<" "<<y1<<" "<<x1-abs(y1-y2)<<" "<<y2<<endl;
        }
        else if(y1==y2)
        {
            if(y1+abs(x1-x2)<=1000 && y1+abs(x1-x2)>=-1000)
                cout<<x1<<" "<<y1+abs(x1-x2)<<" "<<x2<<" "<<y1+abs(x1-x2)<<endl;
            else
                cout<<x1<<" "<<y1-abs(x1-x2)<<" "<<x2<<" "<<y1-abs(x1-x2)<<endl;
        }
        else
        {
            cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
        }
     }
    else
        cout<<"-1"<<endl;
}