#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
    LL n;
    cin>>n;
    unordered_map<LL,LL> m;
    for(int i=0; i<n; i++){
        LL x;
        cin>>x;
        m[x%200]++;
    }

    LL ans=0;
    for(auto c:m){
        ans+=c.second*(c.second-1)/2;
    }
    cout<<ans;
    return 0;
}
