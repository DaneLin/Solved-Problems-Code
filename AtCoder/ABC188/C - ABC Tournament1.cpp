#include<bits/stdc++.h>

using namespace std;

int main()
{
     int n;
     cin>>n;
     int size=1<<n;
     vector<int> a(size);
     for(int i=1;i<=size;i++) cin>>a[i];

     int mpre=-1,pmax=-1;
     int mbac=-1,bmax=-1;

     for(int i=1;i<=size;i++){
         if(i<=size/2){
             if(pmax<a[i]){
                 mpre=i;
                 pmax=a[i];
             }
         }else{
             if(bmax<a[i]){
                 mbac=i;
                 bmax=a[i];
             }
         }
     }

    cout<<(bmax>pmax?mpre:mbac);


    return 0;
}