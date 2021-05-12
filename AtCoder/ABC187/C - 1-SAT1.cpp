#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map<string,int> cnt;
    
    string str="";
    string ans="-";
    for(int i=0; i<n; i++){
        cin>>str;
        if(str[0]=='!'){
            cnt[str]++;
            if(cnt[str.substr(1)]){
                ans=str.substr(1);
            }
        }else{
            cnt[str]++;
            string tmp="!"+str;
            if(cnt[tmp]){
                ans=str;
            }
        }
    }

    if(ans!="-") cout<<ans;
    else cout<<"satisfiable";

    return 0;
}