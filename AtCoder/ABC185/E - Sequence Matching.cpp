#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N], b[N];
int dp[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    memset(dp,0x3f,sizeof dp);
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            //dp[i][j]=min(dp[i][j],dp[i-1][j-1]+2);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }

    cout << dp[n][m];

    return 0;
}