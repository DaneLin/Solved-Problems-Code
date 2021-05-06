#include<bits/stdc++.h>

using namespace std;

int  main()
{
    unsigned long long n;
    cin>>n;
    
    if(n<1000) cout<<0<<endl;
    else
    {
        unsigned long long res=0;
        int cnt=1;
        for(unsigned long long i=1000;i<=n;i*=1000){
            if(i*1000<=n) 
                res+=(i*1000-i)*cnt;
            else res+=(n-i+1)*cnt;
            cnt++;
        }
        cout<<res<<endl;
    }
    
    return 0;
}