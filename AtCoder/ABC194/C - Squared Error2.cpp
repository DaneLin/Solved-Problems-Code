#define LOCAL
#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    int n;
    cin>>n;
    vector<long long> a(n);
    unordered_map<long,long> cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    long long res=0;
    for(int j=-200;j<=200;j++){
        for(int i=-200;i<j;i++){
            res+=cnt[i]*cnt[j]*(i-j)*(i-j);
        }
    }

    cout<<res;

    return 0;
}