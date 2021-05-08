#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m, k;
int num[N];
int a[N], b[N];
int c[N], d[N];
vector<int> q[N];

int ans = 0;

void dfs(int i)
{
    if (i == k)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (num[a[i]] && num[b[i]])
                cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    //试一下左边
    num[c[i]] += 1;
    dfs(i + 1);
    num[c[i]] -= 1;

    num[d[i]] += 1;
    dfs(i + 1);
    num[d[i]] -= 1;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i] >> d[i];
    }
    dfs(0);

    cout << ans;

    return 0;
}