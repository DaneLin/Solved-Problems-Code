#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    int n;
    cin>>n;
    vector<LL> a(n);
    LL tot=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        tot+=a[i];
    }
    sort(a.begin(), a.end());
    LL res=0;

    for(int i=0;i<n;i++){
        res+=tot-(n-i)*a[i];
        tot-=a[i];
    }

    cout<<res<<endl;

    return 0;
}