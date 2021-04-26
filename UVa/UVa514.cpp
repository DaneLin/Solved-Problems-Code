//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef LOCAL
    freopen("514.in", "r", stdin);
    freopen("514.out", "w", stdout);
    #endif

    int n;
    cin>>n;
    while(n!=0)
    {
        vector<int> num(n+1);
        cin>>num[1];
        
        while(num[1]!=0)
        {
            for(int i=2;i<=n;i++) cin>>num[i];
            stack<int> stk;
            int cnt=1;
            for(int i=1;i<=n;i++)
            {
                if(i==num[cnt])
                {
                    cnt++;
                    continue; 
                }
                else
                {
                    while(stk.size()&&num[cnt]==stk.top())
                    {
                        cnt++;
                        stk.pop();
                    }
                    stk.push(i);
                }
            }
            while(stk.size()&&num[cnt]==stk.top())
            {
                cnt++;
                stk.pop();
            }

            if(stk.empty()) puts("Yes");
            else puts("No");
            cin>>num[1];
        }
        cin>>n;
        cout<<endl;
    }
    return 0;
}