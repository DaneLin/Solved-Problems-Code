#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N=20;
const int M=3010;

int n,m;
int v[N];
LL f[M];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i];

    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            f[j]+=f[j-v[i]];
        }
    }

    cout<<f[m];


    return 0;
}