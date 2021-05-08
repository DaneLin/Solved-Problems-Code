#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n),p(n),x(n);
    for(int i=0;i<n;i++) cin>>a[i]>>p[i]>>x[i];

    int minused=(int)1e9;
    bool canget=false;
    for(int i=0;i<n;i++){
        if(x[i]-a[i]>0){
            minused=min(p[i],minused);
            canget=true;
        }
    }   

    if(canget) cout<<minused;
    else cout<<-1<<endl;


    return 0;
}