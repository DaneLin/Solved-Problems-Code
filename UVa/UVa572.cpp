//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=110;

int r,c;
char g[N][N];

void dfs(int x,int y){
    //先判断是否合法
    if(x<0||x>=r||y<0||y>=c) return;
    if(g[x][y]!='@') return;
    g[x][y]='*';
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            dfs(x+dx,y+dy);
        }
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    while(scanf("%d%d",&r,&c))
    {
        getchar();
        if(!r&&!c) break;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                g[i][j]=getchar();
            }
            getchar();
        }
        int cnt=0;
        for(int i=0;i<r; i++){
            for(int j= 0; j < c; j++){
                if(g[i][j]=='@'){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }


    return 0;
}