#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    bool has_square=false;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int t=(int)sqrt(x);
        if(t*t!=x) has_square=true;
    }

    cout<<(has_square?"YES":"NO")<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        solve();


    return 0;
}