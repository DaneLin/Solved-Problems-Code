#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{

    LL res=0,sum=0;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        res+=a[i]*a[i];
        sum+=a[i];
    }

    cout<<n*res-sum*sum<<endl;
    
    return 0;
}