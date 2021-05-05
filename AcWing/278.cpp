#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=110;
const int M=10010;

int n,m;
int num[N],f[N][M];

int main()
{
#ifdef LOCAL
freopen("a.in", "r",stdin);
freopen("a.out", "w",stdout);
#endif
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];

    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=num[i]) f[i][j]+=f[i-1][j-num[i]];
        }
    }

    cout<<f[n][m];


    return 0;
}