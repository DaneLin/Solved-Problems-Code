#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=110;

int n,s,d;
int x[N],y[N];

int main()
{
    #ifdef LOCAL
    freopen("a.in", "r",stdin);
    freopen("a.out", "w",stdout);
    #endif
    cin>>n>>s>>d;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    bool can=false;

    for(int i=0;i<n;i++){
        if(x[i]<s&&y[i]>d){
            can=true;
            break;
        }
    }

    if(can) puts("Yes");
    else puts("No");


    return 0;
}