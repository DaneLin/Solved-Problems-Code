#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,w;
    cin>>a>>b>>w;
    w*=1000;
    int miu=0,mau=0;
    int gap=b-a;
    int cnt=w/a,lef=w%a;
    if(cnt*gap<lef)
        cout<<"UNSATISFIABLE";
    else
    {
        
        miu=w/b;
        if(w%b) miu++;

        mau=cnt;
        if(cnt*gap<lef) mau++;

        cout<<miu<<" "<<mau;
    }
    return 0;
}