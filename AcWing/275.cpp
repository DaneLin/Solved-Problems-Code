#include<string.h>
#include<iostream>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
const int N=60;

int r,c;
int g[N][N];
int dp[N][N][N][N];


int run()
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            for(int k=1;k<=r;k++)
            {
                for(int o=1;o<=c;o++)
                {
                    dp[i][j][k][o]=max(max(dp[i-1][j][k-1][o],dp[i-1][j][k][o-1]),max(dp[i][j-1][k-1][o],dp[i][j-1][k][o-1]))+g[i][j]+g[k][o];
                    if(i==k&&j==o)
                        dp[i][j][k][o]-=g[i][j];
                }
            }
        }
    }
    return dp[r][c][r][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>g[i][j];

    cout<<run()<<endl;

    return 0;
}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N=60;

int g[N][N];
int dp[N+N][N][N];


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
        }
    }

    for(int k=2;k<=n+m;k++)
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++)
            {
                int j1=k-i1,j2=k-i2;
                if(j1>=1&&j1<=m&&j2>=1&&j2<=m) 
                {
                    int t=g[i1][j1];
                    if(i1!=i2) t+=g[i2][j2];
                    int &x=dp[k][i1][i2];
                    x=max(x,dp[k-1][i1-1][i2]+t);
                    x=max(x,dp[k-1][i1-1][i2-1]+t);
                    x=max(x,dp[k-1][i1][i2]+t);
                    x=max(x,dp[k-1][i1][i2-1]+t);
                }
            }

    cout<<dp[n+m][n][n];

    return 0;
}
