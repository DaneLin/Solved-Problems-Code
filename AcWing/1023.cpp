#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n;
int cost[]={10,20,50,100};
int f[N];

int main()
{
    cin>>n;
    f[0]=1;
    for(int i=0;i<4;i++){
        for(int j=cost[i];j<=n;j++){
            f[j]+=f[j-cost[i]];
        }
    }
    cout<<f[n];

    return 0;
}