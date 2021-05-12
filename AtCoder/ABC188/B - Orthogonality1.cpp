#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    long long res=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        res+=x*a[i];
    }

    if(res==0) puts("Yes");
    else puts("No");

    return 0;
}