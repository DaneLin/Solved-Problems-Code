#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
    int n;
    cin>>n;


    LL pre=1;
    LL cur=0;
    for(int i=0; i<11; i++)
    {
        cur=pre*(n-(i+1))/(i+1);
        pre=cur;
    }

    cout<<cur<<" "<<endl;

    return 0;
}