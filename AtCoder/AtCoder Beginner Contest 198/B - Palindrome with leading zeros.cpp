#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;

    long long tmp=n;
    long long num=0;
    long long len=1;
    bool flag=true;
    while(tmp>0){
        if(flag&&tmp%10==0) len*=10;
        else flag=false;
        num=num*10+tmp%10;
        tmp/=10;
    }
    num*=len;

    cout<<(num==n?"Yes":"No")<<endl;

    return 0;
}