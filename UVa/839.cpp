#define LOCAL
#include<bits/stdc++.h>

using namespace std;

bool solve(int &w)
{
    int wl,dl,wr,dr;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    bool left=true,right=true;
    if(!wl) left=solve(wl);
    if(!wr) right=solve(wr);
    w=wl+wr;
    return left&&right&&wl*dl==wr*dr;
}

int main()
{
    #ifdef LOCAL
    freopen("a.in", "r",stdin);
    freopen("a.out", "w",stdout);
    #endif
    int t;
    cin>>t;

    while(t--)
    {
        int w;
        if(solve(w)) puts("YES");
        else puts("NO");
        if(t) printf("\n");
    }


    return 0;
}