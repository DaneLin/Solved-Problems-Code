#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

void print(vector<int> arr){
    cout<<arr.size();
    for(auto c:arr){
        cout<<" "<<c;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin>>a[i];

    int cnt=min(8,n);
    vector<int> rem[201];
    for(int i=1;i<1<<cnt;i++){
        int seg=0;  
        vector<int> tmp;
        for(int j=0;j<cnt;j++){
            if(i&(1<<j)){
                tmp.push_back(j+1);
                seg+=a[j];
                seg%=200;
            }
        }

        if(rem[seg].size()!=0){
            cout<<"Yes"<<endl;
            print(rem[seg]);
            print(tmp);
            return 0;
        }
        else
        {
            rem[seg]=tmp;
        }
    }
    cout<<"No"<<endl;

    return 0;
}
