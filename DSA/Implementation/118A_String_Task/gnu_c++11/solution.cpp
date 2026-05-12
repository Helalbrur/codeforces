// String Task (CF 118A)
// Rating  : 1000
// Tags    : implementation, strings
// Lang    : GNU C++11
// Solved  : 2017-01-03
// Attempt : #1
// URL     : https://codeforces.com/contest/118/problem/A

#include<bits/stdc++.h>
using namespace std;
#define mx 1000
bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='y'||ch=='Y')
        return true;
    return false;
}
void deleteVowel(char text[])
{
    char temp[mx];
    int j=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(isVowel(text[i]))
            continue;
        else{
            temp[j++]='.';
            temp[j++]=tolower(text[i]);
        }
     }
    temp[j]='\0';
    for(int i=0;i<j;i++)
    {
        text[i]=temp[i];
    }
    text[j]='\0';
}
int main()
{
    char text[mx];
    cin>>text;
    deleteVowel(text);
    cout<<text<<endl;
 }