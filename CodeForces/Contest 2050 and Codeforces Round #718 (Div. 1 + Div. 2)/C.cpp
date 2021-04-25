#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0; i<n; i++) cin>>num[i];

    vector<vector<int> > g(n,vector<int>(n));
    for(int i=0; i<n; i++)
        g[i][i]=num[i];
    
    for(int i=0; i<n; i++)
    {
        int cnt=num[i]-1;
        int row=i;
        int col=i;
        while(cnt!=0)
        {
            if(col>0&&g[row][col-1]==0)
            {
                for(col=col-1;col>=0;col--)
                {
                    if(cnt==0) break;
                    if(g[row][col]==0)
                    {
                        g[row][col]=num[i];
                        cnt--;
                    }
                    else
                    {
                        col=col+1;
                        break;
                    }
                }
            }
            else
            {
                row++;
                if(col==-1) col=0;
                g[row][col]=num[i];
                cnt--;
            }
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();

    return 0;
}