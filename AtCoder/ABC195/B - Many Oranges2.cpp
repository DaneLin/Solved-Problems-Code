#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,w;
    cin>>a>>b>>w;
    w*=1000;

    int x=(w+b-1)/b;
    int y=w/a;
    if(x>y) cout<<"UNSATISFIABLE"<<endl;
    else 
        cout<<x<<" "<<y<<endl;
    return 0;
}