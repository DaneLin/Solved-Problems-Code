#define LOCAL
#include<bits/stdc++.h>

using namespace std;

struct node{
    int a,b;

    bool operator<(const node& n) const{
        return a+b<n.a+n.b;
    }
};

int main()
{
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<node> em(n);
    for(int i=0;i<n;i++) cin>>em[i].a>>em[i].b;

    sort(em.begin(),em.end());
    int res=em[0].a+em[0].b;

    int ma=1e6;
    int mb=1e6;
    for(int i=0;i<n;i++){
        if(em[i].a<ma){
            ma=em[i].a;
        }else if(em[i].b<mb){
            mb=em[i].b;
        }
    }

    res=min(res,max(ma,mb));
    mb=1e6;
    ma=1e6;
    for(int i=0;i<n;i++){
        if(em[i].b<mb){
            mb=em[i].b;
        }else if(em[i].a<ma){
            ma=em[i].a;
        }
    }
    res=min(res,max(ma,mb));
    cout<<res<<endl;
    return 0;
}