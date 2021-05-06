<<<<<<< HEAD
//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=100010;

int kase=0;
int n,m;
int pre[N],nex[N];

int type,x,y;

void link(int x,int y)
{
    nex[x]=y;
    pre[y]=x;
}

int main()
{
    #ifdef LOCAL
    freopen("12657.in", "r", stdin);
    freopen("12657.out", "w", stdout);

    #endif

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            pre[i]=i-1;
            nex[i]=(i+1)%(n+1);
        }

        nex[0]=1,pre[0]=n;
        int inv=0;
        while(m--)
        {
            scanf("%d",&type);

            if(type==4) inv=!inv;
            else
            {
                scanf("%d%d",&x,&y);
                if(type==3&&nex[y]==x) swap(x,y);
                if(type!=3&&inv) type=3-type;
                if(type==1&&x==pre[y]) continue;
                if(type==2&&x==nex[y]) continue;
                int lx=pre[x],rx=nex[x],ly=pre[y],ry=nex[y];
                if(type==1)
                {
                    link(lx,rx),link(ly,x),link(x,y);
                }
                else if(type==2)
                {
                    link(lx,rx),link(y,x),link(x,ry);
                }
                else if(type==3)
                {
                    if(nex[x]==y) 
                    {
                        link(lx,y),link(y,x),link(x,ry);
                    }
                    else
                    {
                        link(lx,y),link(y,rx),link(ly,x),link(x,ry);
                    }
                }
            }
        }
        int cur=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cur=nex[cur];
            if(i&1) ans+=cur;
        }

        if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
=======
//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=100010;

int kase=0;
int n,m;
int pre[N],nex[N];

int type,x,y;

void link(int x,int y)
{
    nex[x]=y;
    pre[y]=x;
}

int main()
{
    #ifdef LOCAL
    freopen("12657.in", "r", stdin);
    freopen("12657.out", "w", stdout);

    #endif

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            pre[i]=i-1;
            nex[i]=(i+1)%(n+1);
        }

        nex[0]=1,pre[0]=n;
        int inv=0;
        while(m--)
        {
            scanf("%d",&type);

            if(type==4) inv=!inv;
            else
            {
                scanf("%d%d",&x,&y);
                if(type==3&&nex[y]==x) swap(x,y);
                if(type!=3&&inv) type=3-type;
                if(type==1&&x==pre[y]) continue;
                if(type==2&&x==nex[y]) continue;
                int lx=pre[x],rx=nex[x],ly=pre[y],ry=nex[y];
                if(type==1)
                {
                    link(lx,rx),link(ly,x),link(x,y);
                }
                else if(type==2)
                {
                    link(lx,rx),link(y,x),link(x,ry);
                }
                else if(type==3)
                {
                    if(nex[x]==y) 
                    {
                        link(lx,y),link(y,x),link(x,ry);
                    }
                    else
                    {
                        link(lx,y),link(y,rx),link(ly,x),link(x,ry);
                    }
                }
            }
        }
        int cur=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cur=nex[cur];
            if(i&1) ans+=cur;
        }

        if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
>>>>>>> 282dd16250c70ad757ad3c44b3e84f55d039151a
}