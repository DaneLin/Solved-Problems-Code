//#define LOCAL
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int N=100010;

int last,cur;
int nex[N];
char str[N];

int main()
{
    #ifdef LOCAL
    freopen("11988.in", "r", stdin);
    freopen("11988.out", "w", stdout);
    #endif
    while(scanf("%s",str+1)==1)
    {
        int len=strlen(str+1);

        nex[0]=0;
        last=cur=0;

        for(int i=1;i<=len;i++)
        {
            if(str[i]=='[') cur=0;
            else if(str[i]==']') cur=last;
            else
            {
                nex[i]=nex[cur];
                nex[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }

        }

        for(int i=nex[0];i!=0;i=nex[i])
        {
            printf("%c",str[i]);
        }
        cout<<endl;
    }


    return 0;
}