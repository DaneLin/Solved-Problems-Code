#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;

const int mod=(int)1e9+7;

LL qmi(LL x,LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<qmi(n,k)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        solve();

    return 0;
}