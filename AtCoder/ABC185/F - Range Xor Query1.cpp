#include<bits/stdc++.h>

using namespace std;

const int N=300010;

int n,q;
int a[N];
struct node
{
    int l,r;
    int sum;
}tr[N*4];

void pushup(int x)
{
    tr[x].sum=tr[x<<1].sum^tr[x<<1|1].sum;
}

void build(int x,int l,int r)
{
    tr[x]={l,r,a[l]};
    if(l==r) return;
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void modify(int x,int l,int d)
{
    if(tr[x].l==l&&tr[x].r==l) 
    {
        tr[x].sum^=d;
        return; //
    }
    
    int mid=(tr[x].l+tr[x].r)>>1;   
    if(l<=mid) modify(x<<1,l,d);
    else modify(x<<1|1,l,d);
    pushup(x);
}

int query(int x,int l,int r)
{
    if(tr[x].l>=l&&tr[x].r<=r)
    {
        return tr[x].sum;
    }
    int mid=(tr[x].l+tr[x].r)>>1;
    int ans=0;
    if(l<=mid) ans^=query(x<<1,l,r);
    if(r>mid) ans^=query(x<<1|1,l,r);
    return ans;
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            modify(1,x,y);
        }
        else
        {
            cout<<query(1,x,y)<<endl;
        }
        
    }

    return 0;
}