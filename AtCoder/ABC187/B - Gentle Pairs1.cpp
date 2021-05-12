#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> x(n),y(n);

    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double slope=1.0*(y[j]-y[i])/(x[j]-x[i]);
            //cout<<slope<<endl;
            if(-1<=slope&&slope<=1) ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}