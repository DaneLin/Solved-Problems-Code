#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n;
int height[N];
int dp[N];
int g[N],hh;

int main()
{
    while(cin>>height[n]) n++;

    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(height[j]>=height[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int k=0;
        while(k<cnt&&g[k]<height[i]) k++;
        g[k]=height[i];
        if(k>=cnt) cnt++;
    }

    cout<<cnt;

    return 0;
}