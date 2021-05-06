<<<<<<< HEAD
#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=20;

int main()
{
    #ifdef LOCAL
    freopen("679.in", "r",stdin);
    freopen("679.out", "w", stdout);
    #endif
    int t;
    cin>>t;
    
    int dep,num;
    while(scanf("%d%d",&dep,&num)==2){
        int k=1;
        for(int i=0;i<dep-1;i++)
        {
            if(num&1)
            {
                k=k*2;
                num=(num+1)/2;
            }
            else
            {
                k=k*2+1;
                num=num/2;
            }
        }
        cout<<k<<endl;
    }     


    return 0;
=======
#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=20;

int main()
{
    #ifdef LOCAL
    freopen("679.in", "r",stdin);
    freopen("679.out", "w", stdout);
    #endif
    int t;
    cin>>t;
    
    int dep,num;
    while(scanf("%d%d",&dep,&num)==2){
        int k=1;
        for(int i=0;i<dep-1;i++)
        {
            if(num&1)
            {
                k=k*2;
                num=(num+1)/2;
            }
            else
            {
                k=k*2+1;
                num=num/2;
            }
        }
        cout<<k<<endl;
    }     


    return 0;
>>>>>>> 282dd16250c70ad757ad3c44b3e84f55d039151a
}