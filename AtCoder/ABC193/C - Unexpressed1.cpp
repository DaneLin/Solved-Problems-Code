#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
    LL n = 0;
    cin>>n;

    unordered_set<LL> s;
    for(LL i=2;i<=n/i;i++){
        LL x=i*i;
        while(x<=n){
            s.insert(x);
            x*=i;
        }
    }

    cout<<n-s.size()<<endl;
    return 0;
}