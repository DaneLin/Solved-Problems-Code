#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<vector<int> > hor(n,vector<int>(m));
    vector<vector<int> > ver(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            cin>>hor[i][j];
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ver[i][j];
        }
    }

    vector<vector<int> > ans(n,vector<int>(m,0));
    if(k&1)
    {
        ans.assign(n,vector<int>(m,-1));
    }
    else
    {
        vector<vector<int> > new_ans(n,vector<int>(m,0));

        for(int it=0;it<k/2;it++)
        {
            for (int i = 0; i < n; i++)
            {
                for(int j= 0; j <m;j++)
                {
                    new_ans[i][j]=(int)1e9;
                    if(i>0)
                    {
                        new_ans[i][j]=min(new_ans[i][j],ans[i-1][j]+2*ver[i-1][j]);
                    }
                    if(j>0)
                    {
                        new_ans[i][j]=min(new_ans[i][j],ans[i][j-1]+2*hor[i][j-1]);
                    }
                    if(i<n-1)
                    {
                        new_ans[i][j]=min(new_ans[i][j],ans[i+1][j]+2*ver[i][j]);
                    }
                    if(j<m-1)
                    {
                        new_ans[i][j]=min(new_ans[i][j],ans[i][j+1]+2*hor[i][j]);
                    }
                }
            }
            swap(ans,new_ans);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j) cout<<' ';
            cout<<ans[i][j];
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