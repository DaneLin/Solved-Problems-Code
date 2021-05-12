#include<bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int n,q;
int bit[N];

int lowbit(int x)
{
    return x&(-x);
}

int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s^=bit[i];
        i-=lowbit(i);
    }
    return s;
}

void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]^=x;
        i+=lowbit(i);
    }
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        add(i,t);
    }

    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1) add(x,y);
        else cout<<(sum(y)^sum(x-1))<<endl;
    }


    return 0;
}