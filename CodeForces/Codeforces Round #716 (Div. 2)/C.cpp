#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n;
    cin>>n;

    vector<int> num;
    LL product=1;
    for(int i=1;i<n;i++)
    {
        if(gcd(i,n)==1)
        {
            num.push_back(i);
            product=product*i%n;
        }
    }


    if(product!=1)
    {
        vector<int> ans;
        for(int i=0;i<(int)num.size();i++)
        {
            if(num[i]==product) continue;
            ans.push_back(num[i]);
        }
        num=ans;
    }
    

    cout<<(int)num.size()<<endl;
    for(auto c:num)
        cout<<c<<' ';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--)
        solve();


    return 0;
}
