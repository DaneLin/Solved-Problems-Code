#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{ 
    int n;
    cin>>n;
    vector<LL> a(n);

    LL res=0,tot=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        res+=a[i]*a[i];
        tot+=a[i];
    }

    LL tmp=0;
    for(int i=0;i<n;i++) tmp-=a[i]*(tot-a[i]);
    
    cout<<res*(n-1)+tmp<<endl;

    return 0;
}