#include<bits/stdc++.h>

using namespace std;

const int N=1e3+10;

double v[N],p[N];

int main()
{
    double n,x;
    cin>>n>>x;
    
    for(int i=1;i<=(int)n;i++) cin>>v[i]>>p[i];

    double get=0.0;
    int pos=0;
    for(int i=1;i<=n;i++){
        get+=v[i]*p[i]/100.0;
        if(get-x>1e-6){
            pos=i;
            break;
        } 
    }
    cout<<(pos?pos:-1);

    return 0;
}