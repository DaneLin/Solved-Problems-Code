#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int a[N];
int q[N],tt;
int l[N],r[N];

int main()
{
//单调队列
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    a[0]=a[n+1]=0;
    q[++tt]=0;
    for(int i=1;i<=n;i++){
        while(tt&&a[q[tt]]>=a[i])
            tt--;
        l[i]=q[tt];
        q[++tt]=i;
    }
    tt=0;
    q[++tt]=n+1;
    for(int i=n;i>=1;i--){
        while(tt&&a[q[tt]]>=a[i])
            tt--;
        r[i]=q[tt];
        q[++tt]=i;
    }

    int res=0;

    for(int i=1;i<=n;i++){
        //cout<<l[i]<<' '<<r[i]<<endl;
        res=max(res,(r[i]-l[i]-1)*a[i]);
    }

    cout<<res<<endl;
    return 0;
}