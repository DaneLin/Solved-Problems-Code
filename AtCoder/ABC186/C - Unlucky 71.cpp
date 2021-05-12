#include<bits/stdc++.h>

using namespace std;

bool d(int num){
    while(num){
        if(num%10==7) return false;
        num/=10;
    }
    return true;
}

bool o(int num){
    while(num){
        if((num&7)==7) return false;
        num>>=3;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    int ans=0;
    for(int i=1;i<=n;i++){
        if(d(i)&&o(i)) ans++;
    }
    cout<<ans<<endl;

    return 0;
}