// Interview with Oleg (CF 738A)
// Rating  : 900
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2016-11-20
// Attempt : #1
// URL     : https://codeforces.com/contest/738/problem/A

#include<bits/stdc++.h>
using namespace std;
int main(){
     int n;
    string helal;
    //freopen("i.txt","r",stdin);
    cin>>n;
    cin>>helal;
    int flag=0;
    for(int i=0;i<helal.length();i++)
    {
        if(helal[i]=='o')
        {
            int j=i;
            while(j<helal.length()  && helal[j+2]=='o' && helal[j+1]=='g')
            {
                     j=j+2;
                    flag=1;
            }
            if(flag==1)
            {
                cout<<"***";
                i=j;
                flag=0;
            }
            else
                cout<<helal[i];
        }
        else
        {
            cout<<helal[i];
            flag=0;
        }
     }
    cout<<endl;
}