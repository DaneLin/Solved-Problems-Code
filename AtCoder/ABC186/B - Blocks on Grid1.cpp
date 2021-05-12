#include<bits/stdc++.h>

using namespace std;

const int N=110;

int g[N][N];

int main()
{
    int h,w;
    cin>>h>>w;

    int mmin=(int)110;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>g[i][j];
            mmin=min(mmin,g[i][j]);
        }
    }

    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            ans+=g[i][j]-mmin;
        }
    }

    cout<<ans;

    return 0;
}