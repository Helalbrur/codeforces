// Stepan and Vowels (CF 795K)
// Rating  : 1600
// Tags    : *special, implementation, strings
// Lang    : GNU C11
// Solved  : 2017-04-05
// Attempt : #1
// URL     : https://codeforces.com/contest/795/problem/K

#include<stdio.h>
#include<string.h>
int main()
{
    int n,j,len=0,p=0,i=0;
    //freopen("vk.txt","r",stdin);
    scanf("%d",&n);
    char text[n+4],s[n+4];
    getchar();
    gets(text);
    len=strlen(text);
    for( i=0;i<len;i++)
    {
        j=0;
        s[p++]=text[i];
        if(text[i]=='a')
        {
            for (j=0;j<len;j++)
            {
                if(text[j+i]!='a')
                    break;
            }
            j--;
            if(j<0)
                j=0;
           i=i+j;
        }
        else if(text[i]=='y')
        {
            for (j=0;j<len;j++)
            {
                if(text[j+i]!='y')
                    break;
            }
            j--;
            if(j<0)
                j=0;
           i=i+j;
        }
        else if(text[i]=='i')
        {
            for( j=0;j<len;j++)
            {
                if(text[j+i]!='i')
                    break;
            }
            j--;
            if(j<0)
                j=0;
           i=i+j;
        }
        else if(text[i]=='u')
        {
            for( j=0;j<len;j++)
            {
                if(text[j+i]!='u')
                    break;
            }
            j--;
            if(j<0)
                j=0;
           i=i+j;
        }
        else if(text[i]=='o')
        {
            for (j=0;j<len;j++)
            {
                if(text[j+i]!='o')
                    break;
            }
            j--;
            if(j<0)
                j=0;
            if(j==1)
            {
                s[p++]='o';
            }
             i=i+j;
        }
        else if(text[i]=='e')
        {
            for (j=0;j<len;j++)
            {
                if(text[j+i]!='e')
                    break;
            }
            j--;
            if(j<0)
                j=0;
            if(j==1)
            {
                 s[p++]='e';
            }
             i=i+j;
        }
    }
    s[p]='\0';
    puts(s);
}