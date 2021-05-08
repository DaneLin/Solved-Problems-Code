#define LOCAL
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;

int main()
{
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<PII> em(n);
    for(int i=0;i<n;i++) cin>>em[i].first>>em[i].second;

    int res=1e6;
    //直接穷举所有可能性
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res=min(res,(i==j?em[i].second+em[i].first:max(em[i].first,em[j].second)));
        }
    }
    cout<<res<<endl;
    return 0;
}