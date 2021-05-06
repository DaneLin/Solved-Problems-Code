#define DEBUG
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int M = 510;
const int K = 110;

int n, m, k;
int v[K], d[K];
int f[N][M];

int main()
{
#ifdef DEBUG
freopen("a.in", "r",stdin);
freopen("a.out", "w",stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> v[i] >> d[i];
    }

    int mcnt = 0, mres = m;
    for (int i = 1; i <= k; i++)
    {
        for (int j = n; j >= v[i]; j--)
        {
            for (int s = m; s >= d[i]; s--)
            {
                f[j][s] = max(f[j][s], f[j - v[i]][s - d[i]] + 1);
                if (f[j][s] > mcnt)
                {
                    mcnt = f[j][s];
                    mres = s;
                }
                else if (f[j][s] == mcnt)
                    mres = min(mres, s);
                //cout<<mres<<endl;
            }
        }
    }
    mres=(mcnt)?m-mres:m;
    cout << mcnt << ' ' << mres;


    return 0;
}