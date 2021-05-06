#include<bits/stdc++.h>

using namespace std;

const int N=30;

int n;
int num[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];


    int res=1<<30;

    for(int i=0;i<(1<<20);i++)
    {
        int xord=0;
        int ord=0;
        for(int j=0;j<=n;j++){
            if(j<n) ord|=num[j];
            if(j==n||(i>>j)&1) xord^=ord,ord=0;
        }
        res=min(res,xord);
    }
    cout<<res<<endl;

    return 0;
}