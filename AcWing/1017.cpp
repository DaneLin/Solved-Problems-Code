#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const int N=110;

int h[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }

    vector<int> dp(n);

    int res=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(h[i]>h[j])
                dp[i]=max(dp[i],dp[j]+1);
       
        res=max(res,dp[i]);
    }  

    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(h[i]<h[j])
                dp[i]=max(dp[i],dp[j]+1);
       
        res=max(res,dp[i]);
    }  

    cout<<res<<endl;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        solve();

    return 0;
}