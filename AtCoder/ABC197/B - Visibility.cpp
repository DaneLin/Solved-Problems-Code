#include<bits/stdc++.h>

using namespace std;

const int N=110;

char g[N][N];

int main()
{
    int h,w,x,y;
    cin>>h>>w>>x>>y;

    for(int i=1;i<=h;i++){
        scanf("%s",g[i]+1);
    }

    int res=0;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    for(int i=0;i<4;i++){
        int nx=x,ny=y;
        while(nx>=1&&nx<=h&&ny>=1&&ny<=w&&g[nx][ny]!='#'){
            res++;
            nx+=dx[i];
            ny+=dy[i];
        }
    }
    
    cout<<res-3<<endl;

    return 0;
}