#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> path(n,vector<int>(m));
    vector<int> tmp(m);
    vector<int> cnt(m);
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<m;j++)
        {
            cin>>tmp[j];
        }
        sort(tmp.begin(),tmp.end());
        if(i==0)
        {
            path[i]=tmp;
            cnt=tmp;
        }
        else
        {
            if(*max_element(cnt.begin(),cnt.end())<=tmp[0])
            {
                path[i]=tmp;
                continue;
            }
            vector<int> after(m);
            int j;
            for(j=0;j<m;j++)
            {
                int pos=max_element(cnt.begin(),cnt.end())-cnt.begin();
                int num=cnt[pos];
                if(num>tmp[j])
                {
                    after[pos]=tmp[j];
                    cnt[pos]=tmp[j];
                    tmp[j]=0;
                }
                else
                {
                    break;
                }
            }
            for(int k=0;k<m;k++){
                if(after[k]!=0) continue;
                after[k]=tmp[j++];
            }

            path[i]=after;
        }
        
    }


    for(int i=0;i<n;i++)
    {
        for(int j= 0; j < m; j++)
        {
            cout<<path[i][j]<<' ';
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
    cin>>t;

    while(t--)
        solve();

    return 0;
}