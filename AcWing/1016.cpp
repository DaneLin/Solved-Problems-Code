#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int num[N];
int dp[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];

    for(int i=0;i<n;i++)
    {
        dp[i]=num[i];
        for(int j=0;j<i;j++)
            if(num[j]<num[i])
                dp[i]=max(dp[i],dp[j]+num[i]);
    }

    int res=0;
    for(int i=0;i<n;i++) res=max(res,dp[i]);

    cout<<res<<endl;


    return 0;
}
