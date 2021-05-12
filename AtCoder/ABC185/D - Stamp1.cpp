#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> pos(m);
    for(int i=0;i<m;i++) 
        cin>>pos[i];
    pos.push_back(n+1);

    vector<int> cnt;
    sort(pos.begin(),pos.end());
    
    int pre=0;
    int mmin=(int)1e9;
    for(int i=0;i<(int)pos.size();i++)
    {
        int gap=pos[i]-pre-1;
        pre=pos[i];
        if(!gap) continue;
        mmin=min(mmin,gap);
        cnt.push_back(gap);
    }

    long long ans=0;

    for(int i=0;i<(int)cnt.size();i++)
    {
        ans+=(cnt[i]+mmin-1)/mmin;
    }

    cout<<ans;

    return 0;
}