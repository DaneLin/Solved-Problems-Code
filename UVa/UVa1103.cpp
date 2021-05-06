#define DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int H = 210, W = 210;
//不相交，每个象形文字都是独立存在的
//1 3 5 4 0 2 每个象形文字有的空洞
char ch[] = {'W', 'A', 'K', 'J', 'S', 'D'}; //不同洞的数量对应不同的字符
char binary[][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; //四联通

int h, w;     //获取行和列
char g[H][W]; //存储图
char pic[H][H];
int idx[H][H];

//涂色(先涂黑色部分)
void dfs(int x, int y, int id)
{
    queue<PII> q;
    q.push({x, y});
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.first + dx[i], ny = tmp.second + dy[i];
            if (nx > 0 && ny > 0 && nx <= h && ny <= w && !idx[nx][ny] && pic[nx][ny] == '1')
            {
                idx[nx][ny] = id;
                q.push({nx, ny});
            }
        }
    }
}

void bfs(int x, int y, int &id, int &num)
{
    queue<PII> q;
    q.push({x, y});

    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.first + dx[i], ny = tmp.second + dy[i];
            if (nx >= 0 && nx <= h && ny >= 0 && ny <= w)
            {
                if (!idx[nx][ny])
                {
                    idx[nx][ny] = id;
                    q.push({nx, ny});
                }
                else
                    num += (id != idx[nx][ny]);
            }
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int kase = 0;
    while (scanf("%d%d", &h, &w) == 2)
    {
        if (!h && !w)
            break;
        memset(idx, 0, sizeof(idx));
        for (int i = 0; i <= h + 1; i++)
        {
            idx[i][0] = idx[i][w * 4 + 1] = -1;
            if (i == 0 || i == h + 1)
            {
                for (int j = 0; j <= w * 4 + 1; j++)
                {
                    idx[i][j] = -1;
                }
            }
        }

        for (int i = 1; i <= h; i++)
            scanf("%s", g[i] + 1);
        for (int i = 1; i <= h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (isdigit(g[i][j + 1]))
                {
                    for (int k = 0; k < 4; k++)
                    {
                        pic[i][j * 4 + k + 1] = binary[g[i][j + 1] - '0'][k];
                    }
                }
                else
                {
                    for (int k = 0; k < 4; k++)
                    {
                        pic[i][j * 4 + k + 1] = binary[10 + g[i][j + 1] - 'a'][k];
                    }
                }
            }
        }

        w *= 4; //扩大四倍
        int id = 1;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (idx[i][j] == 0 && pic[i][j] == '1')
                    dfs(i, j, id++);
            }
        }

        vector<int> graph(id, 0);
        for (int i = 2; i < h; i++)
        {
            for (int j = 2; j < w; j++)
            {
                if (idx[i - 1][j] && idx[i][j - 1] && idx[i][j] == 0 && pic[i][j] == '0')
                {
                    int cur = idx[i - 1][j], num = 0;
                    bfs(i, j, cur, num);
                    if (num == 0)
                    {
                        graph[cur]++;
                    }
                }
            }
        }
        int cnt[6] = {0};

        string str = "";
        for (int i = 1; i < id; i++)
        {
            str+=ch[graph[i]];
        }
        sort(str.begin(), str.end());
        printf("Case %d: ", ++kase);
        cout << str << endl;
    }
    return 0;
}