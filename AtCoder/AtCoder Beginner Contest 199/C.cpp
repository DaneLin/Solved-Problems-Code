#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,q;
char s[N*2];

int main()
{
    cin>>n;
    scanf("%s",s);
    cin>>q;
    
    bool flag=false;//is reversed?
    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        a--,b--;
        if(t==1){
            if(flag){
                if(a<n) a+=n;
                else a-=n;
                if(b<n) b+=n;
                else b-=n;
            }
            swap(s[a],s[b]);
        }
        else flag=!flag;
    }

    if(flag){
        for(int i=n;i<2*n;i++){
            cout<<s[i];
        }
        for(int i=0;i<n;i++){
            cout<<s[i];
        }
    }else{
        for(int i=0;i<2*n;i++) cout<<s[i];
    }


    return 0;
}