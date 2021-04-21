#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<cmath>

using namespace std;

const int N=110;

int g[N][N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp,0x3f,sizeof dp);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];

    dp[0][1]=dp[1][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+g[i][j];

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<dp[n][n];
        
    return 0;
}