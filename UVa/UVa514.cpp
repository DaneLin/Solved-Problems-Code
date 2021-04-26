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

//Rujia Liu's version
//需要对输入输出有修改才可以通过，这里是原始代码
#include<cstdio>
#include<stack>

using namespace std;
const int N=1010;

int n,target[N];

int main()
{
    while(scanf("%d",&n)==1)
    {
        stack<int> stk;
        int A=1,B=1;
        for(int i=1;i<=n;i++)
            scanf("%d",&target[i]);
        int ok=1;
        while(B<=n)
        {
            if(A==target[B])
            {
                A++,B++;
            }
            else if(!stk.empty()&&stk.top()==target[B])
            {
                stk.pop();
                B++;
            }
            else if(A<=n)
            {
                stk.push(A++);
            }
            else
            {
                ok=0;
                break;
            }
        }
        printf("%s\n",ok?"Yes":"No");
    }
    return 0;
}
