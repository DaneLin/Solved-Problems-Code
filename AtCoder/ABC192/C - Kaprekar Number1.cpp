#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int pre=n;
    vector<int> cnt(10);

    int res=0;
    for(int i=0;i<k;i++){
        res=pre;
        int tmp=res;
        while(tmp){
            cnt[tmp%10]++;
            tmp/=10;
        }

        int f1=0,f2=0;
        for(int i=9;i>=0;i--){
            for(int j=0;j<cnt[i];j++){
                f1=f1*10+i;
            }
        }
        for(int i=0;i<=9;i++){
            while(cnt[i]){
                f2=f2*10+i;
                cnt[i]--;
            }
        }
        pre=f1-f2;
        if(pre==res) break;
    }

    cout<<pre;


    return 0;
}