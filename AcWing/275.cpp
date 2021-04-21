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
