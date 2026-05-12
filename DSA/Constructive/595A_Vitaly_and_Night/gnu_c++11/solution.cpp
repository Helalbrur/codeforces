// Vitaly and Night (CF 595A)
// Rating  : 800
// Tags    : constructive algorithms, implementation
// Lang    : GNU C++11
// Solved  : 2015-11-08
// Attempt : #1
// URL     : https://codeforces.com/contest/595/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    // freopen("a.txt","r",stdin);
    long int sum=0;
    cin>>n>>m;
    int array[1000];
    while(n--)
    {
        int count=0;
         for(int i=0;i<2*m;i++)
        {
            cin>>array[i];
            count++;
            if(count%2==0)
            {
                if(array[i]==1)
                {
                    sum++;
                }
                else if(array[i-1]==1)
                {
                    sum++;
                }
             }
         }
      }
    cout<<sum<<endl;
    sum=0;
}