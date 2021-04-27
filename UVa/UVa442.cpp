//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

int n;
struct Maxtrix
{
    int r,c;
    Maxtrix(int a=0,int b=0){r=a,c=b;}
}m[26];

int main()
{
    #ifdef LOCAL
    freopen("442.in", "r",stdin);
    freopen("442.out", "w", stdout);
    #endif

    cin>>n;
    for(int i=0;i<n;i++)
    {
        string ch;
        cin>>ch;
        cin>>m[ch[0]-'A'].r>>m[ch[0]-'A'].c;
    }
    stack<Maxtrix> stk;
    string expr;
    while(cin>>expr)
    {
        int len=expr.length();
        int ans=0;
        bool is_ok=true;
        for(int i=0;i<len;i++)
        {
            if(isalpha(expr[i])) stk.push(m[expr[i]-'A']);
            else if(expr[i]==')')
            {
                Maxtrix a=stk.top();
                stk.pop();
                Maxtrix b=stk.top();
                stk.pop();
                //cout<<a.c<<' '<<b.r<<endl;
                if(a.r!=b.c)
                {
                    is_ok=false;
                    break;
                }
                ans+=b.r*b.c*a.c;
                stk.push(Maxtrix(b.r,a.c));
            }
        }
        if(!is_ok)
            puts("error");
        else
        {
            cout<<ans<<endl;
        }
    }

    return 0;
}