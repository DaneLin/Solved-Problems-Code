#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;
const int N=5000+10;

struct node
{
    int x,y;
    bool operator<(const node&p) const
    {
        return x<p.x;
    }
}ns[N];

int dp[N];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&ns[i].x,&ns[i].y);
    }

    sort(ns,ns+n);

    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(ns[j].y<ns[i].y)
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    
    int res=0;
    for(int i=0;i<n;i++) res=max(res,dp[i]);

    cout<<res<<endl;

    return 0;
}
