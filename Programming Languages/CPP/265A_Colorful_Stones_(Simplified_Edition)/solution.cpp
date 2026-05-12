// Colorful Stones (Simplified Edition) (CF 265A)
// Rating  : 800
// Tags    : implementation
// Lang    : GNU C++11
// Solved  : 2017-02-11
// Attempt : #1
// URL     : https://codeforces.com/contest/265/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string stone,instruction;
    //freopen("input.txt","r+",stdin);
    cin>>stone>>instruction;
    int l=stone.length();
    int j=0;
    for(int i=0;i<instruction.length();i++)
    {
        if(instruction[i]==stone[j] && j<l-1)
            j++;
    }
    cout<<j+1<<endl;
}