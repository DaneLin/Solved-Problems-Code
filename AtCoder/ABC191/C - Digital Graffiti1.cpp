#define LOCAL
#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
char g[N][N];

int main()
{
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int h, w;
    cin >> h >> w;

    for (int i = 1; i <= h; i++)
    {
        scanf("%s", g[i] + 1);
    }

    int res = 0;
    for (int i = 2; i < h; i++)
    {
        for (int j = 2; j < w; j++)
        {
            if (g[i][j] == '#')
            {
                //上边
                if((g[i][j-1]!='#'&&g[i-1][j]!='#')||(g[i-1][j-1]=='#'&&g[i-1][j]!='#')) 
                    res++;
                //下边
                if((g[i+1][j]!='#'&&g[i][j-1]!='#')||(g[i+1][j-1]=='#'&&g[i+1][j]!='#')) 
                    res++;
                //左边
                if((g[i-1][j]!='#'&&g[i][j-1]!='#')||(g[i-1][j-1]=='#'&&g[i][j-1]!='#')) 
                    res++;
                //右边
                if((g[i-1][j]!='#'&&g[i][j+1]!='#')||(g[i-1][j+1]=='#'&&g[i][j+1]!='#')) 
                    res++;
            }
        }
    }
    cout << res << endl;

    return 0;
}
