#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r,x,y;
    cin>>r>>x>>y;

    double dis=sqrt(pow(x,2)+pow(y,2));

    int res=dis/r;
    if(dis-(r*res)>1e-9)
    {
        if(res) res++;
        else res+=2;
    }

    cout<<res<<endl;

    return 0;
}