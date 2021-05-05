//二维dp
/*
#include<bits/stdc++.h>

using namespace std;

const int N=40;
const int V=20010;

int v,n;
int w[N];
int f[N][V];

int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=v;j++){
            f[i][j]=f[i-1][j];
            if(j>=w[i]) f[i][j]=max(f[i][j],f[i-1][j-w[i]]+w[i]);
        }
    }

    cout<<v-f[n][v]<<endl;


    return 0;
}*/
//优化
#include<bits/stdc++.h>

using namespace std;

const int N=40;
const int V=20010;

int v,n;
int w[N];
int f[V];

int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        for(int j=v;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    }

    cout<<v-f[v];

    return 0;
}