#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=110;

int g[N][N];
int dp[N];//开二维dp

void solve()
{
    int r,c;
    cin>>r>>c;

    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>g[i][j];
    
    memset(dp,0,sizeof dp);

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            dp[j]=max(dp[j],dp[j-1])+g[i][j];
        }
    }

    cout<<dp[c]<<endl;
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