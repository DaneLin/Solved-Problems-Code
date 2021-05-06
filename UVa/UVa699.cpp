//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int maxn=300;

int cnt[maxn]; 
int lef,rig;

void build(int pos)
{
    int val;
    cin>>val;
    if(val==-1) 
        return ;
    cnt[pos]+=val;
    build(pos-1);
    build(pos+1);
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("a.in", "r",stdin);
    freopen("a.out", "w",stdout);
    #endif

    int root=maxn/2;
    int n;
    int kase=0;
    while(scanf("%d",&n)==1){
        if(n==-1) break;
        memset(cnt,0,sizeof cnt);
        cnt[root]=n;
        lef=(int)1e3;
        build(root-1);
        build(root+1);
        int pos=0;
        while(cnt[pos]==0) pos++;
        printf("Case %d:\n%d",++kase,cnt[pos++]);
        while(cnt[pos]!=0) cout<<' '<<cnt[pos++];
        cout<<"\n\n";

    }
    return 0;
}