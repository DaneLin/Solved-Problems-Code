#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    cout<<max(0,b[0]-a[n-1]+1)<<endl;



    return 0;
}