#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,w;
    cin>>a>>b>>w;

    int miu=(int)1e9,mau=0;

    for(int i=1;i<=(int)1e6;i++){
        if(a*i<=w*1000&&w*1000<=b*i){
            miu=min(miu,i);
            mau=max(mau,i);
        }
    }

    if(mau) cout<<miu<<" "<<mau<<endl;
    else cout<<"UNSATISFIABLE"<<endl;




    return 0;
}