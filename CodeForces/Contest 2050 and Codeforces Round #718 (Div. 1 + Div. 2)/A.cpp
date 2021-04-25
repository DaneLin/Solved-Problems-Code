#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

int get(LL num) 
{
    int len=0;
    while(num>0){
        len++;
        num/=10;
    }
    return len;
}

void solve()
{
    LL num;
    cin>>num;

    if(num<2050) puts("-1");
    else
    {
        LL cnt=0;
        LL t=2050;
        int len=get(num);
        for(int i=0;i<len-4;i++){
            t*=10;
        }
        while(num>0&&t>=2050)
        {
            if(num>=t)
            {
                num-=t;
                cnt++;
            }
            else
            {
                t/=10;
                len--;
            }
        }

        if(num==0&&cnt&&t>=2050)
        {
            cout<<cnt<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}

int main()
{
    int t;
    t=1;
    cin>>t;

    while(t--)
        solve();

    return 0;
}