#include<bits/stdc++.h>

using namespace std;

const int T=1010;
const int M=110;

int t,m;
int v[M],w[M];
int f[T];

int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=m;i++){
        for(int j=t;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }

    cout<<f[t]<<endl;



    return 0;
}