#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];

    int res=0;
    vector<int> dp(n);
    
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(h[j]<h[i])
                dp[i]=max(dp[i],dp[j]+1);
        }

    }
    vector<int> down(n);
    for(int i=n-1;i>=0;i--)
    {
        down[i]=1;
        for(int j=n-1;j>i;j--)
        {
            if(h[j]<h[i])
                down[i]=max(down[i],down[j]+1);
        }
    }

    for(int i=0;i<n;i++)
    {
        res=max(res,dp[i]+down[i]-1);
    }

    cout<<n-res<<endl;

    return 0;
}