#include<bits/stdc++.h>

using namespace std;

const int N=1010;

char str[N];

int main()
{
    scanf("%s",str+1);

    bool hard=true;
    //without including the terminating null character itself
    int len=strlen(str+1);
    for(int i=1;i<=len;i++){
        if(i&1){
            if(str[i]>='A'&&str[i]<='Z'){
                hard=false;
                break;
            }
        }else{
            if(str[i]>='a'&&str[i]<='z'){
                hard=false;
                break;
            }
        }
        
    }
    if(hard) puts("Yes");
    else puts("No");


    return 0;
}