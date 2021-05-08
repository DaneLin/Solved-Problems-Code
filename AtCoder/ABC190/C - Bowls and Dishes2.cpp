#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> cood(m);
    for(auto &[a,b]:cood) cin>>a>>b;

    int k=0;
    cin>>k;
    vector<pair<int,int>> choice(k);
    for(auto&[c,d]:choice) cin>>c>>d;

    int ans=0;
    for(int bit=0;bit<1<<k;bit++){
        vector<bool> ball(n);
        for(int i=0;i<k;i++){
            const auto [c,d]=choice[i];
            ball[bit&1<<i?c:d]=1;
        }
        int cnt=0;
        for(auto [a,b]:cood){
            if(ball[a]&&ball[b])
                cnt++; 
        }
        if(ans<cnt) ans=cnt;
    }
    cout<<ans<<endl;

    return 0;
}