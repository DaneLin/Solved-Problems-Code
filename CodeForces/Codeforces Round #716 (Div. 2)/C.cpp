#include<iostream>
#include<queue>

using namespace std;

const int N=30;

int g[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

bool vis[N][N];

bool check(int x,int y)
{
    return true;
}

struct Node
{
    int x,y;
    int step;
};

Node endPos;

int bfs()
{
    int res=0;
    queue<Node> que;
    
    Node x{0,0,0};
    que.push(x);

    while(!que.empty())
    {
        Node tmp=que.front();
        que.pop();

        if(tmp.x==endPos.x&&tmp.y==endPos.y)
        {
            res=tmp.step;
            break;
        }
        //看四个方向
        for(int i=0;i<4;i++)
        {
            int nx=tmp.x+dx[i],ny=tmp.y+dy[i];
            if(check())
                que.push(Node{nx,ny,tmp.step+1});
            
        }
    }

    return res;
}

int main()
{



    return 0;
}