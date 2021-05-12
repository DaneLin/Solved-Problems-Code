#include<bits/stdc++.h>

using namespace std;

const int M=1010;

int a[M],b[M];

int main()
{
    int n,m,t;
    cin>>n>>m>>t;

    for(int i=0;i<m;i++) cin>>a[i]>>b[i];

    bool flag=true;
    int cur=n,pre=0;
    for(int i=0;i<m;i++){
        int gap=a[i]-pre;
        cur-=gap;
        if(cur<=0){
            flag=false;
            break;
        }
        
        int add=b[i]-a[i];
        cur=(cur+add>=n?n:cur+add);
        pre=b[i];
    }
    cur-=t-pre;
    if(cur<=0){
        flag=false;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}