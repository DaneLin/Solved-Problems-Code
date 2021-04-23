
//时间复杂度O(n^4)
#include<string.h>
#include<iostream>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
const int N=15;

int n;
int g[N][N];
int dp[N][N][N][N];


int run()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int o=1;o<=n;o++)
                {
                    dp[i][j][k][o]=max(max(dp[i-1][j][k-1][o],dp[i-1][j][k][o-1]),max(dp[i][j-1][k-1][o],dp[i][j-1][k][o-1]))+g[i][j]+g[k][o];
                    if(i==k&&j==o)
                        dp[i][j][k][o]-=g[i][j];
                }
            }
        }
    }
    return dp[n][n][n][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    int r,c,num;
    while(cin>>r>>c>>num,r||c||num)
    {
        g[r][c]=num;
    }

    cout<<run()<<endl;

    return 0;
}


//时间复杂度O(n^3)
#include<string.h>
#include<iostream>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
const int N=15;

int n;
int g[N][N];
int dp[N+N][N][N];


int run()
{
    for(int k=1;k<=n+n;k++)
    {
        for(int i1=1;i1<=n;i1++)
        {
            for(int i2=1;i2<=n;i2++)
            {
                int j1=k-i1,j2=k-i2;
                if(j1>=1&&j1<=n&&j2>=1&&j2<=n)
                {
                    int t=g[i1][j1];
                    if(i1!=i2)
                        t+=g[i2][j2];
                    //四种情况
                    int &x=dp[k][i1][i2];
                    x=max(x,dp[k-1][i1-1][i2-1]+t);
                    x=max(x,dp[k-1][i1-1][i2]+t);
                    x=max(x,dp[k-1][i1][i2-1]+t);
                    x=max(x,dp[k-1][i1][i2]+t);
                }
            }
        }
    }
    return dp[n+n][n][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    int r,c,num;
    while(cin>>r>>c>>num,r||c||num)
    {
        g[r][c]=num;
    }

    cout<<run()<<endl;

    return 0;
}
