//#define LOCAL
#include<bits/stdc++.h>

using namespace std;

const int N=10010;

int inorder[N],postorder[N];
int lch[N],rch[N];

int n;
//建树过程
int build_tree(int inl,int inr,int pol,int por)
{
    if(inl>inr) return 0;//空树
    
    int root=postorder[por];
    int pos=inl;
    while(inorder[pos]!=root) pos++;
    int cnt=pos-inl;
    lch[root]=build_tree(inl,pos-1,pol,pol+cnt-1);
    rch[root]=build_tree(pos+1,inr,pol+cnt,por-1);
    return root;
}
//读入
bool read_input(int *a)
{
    n=0;
    string str;
    if(!getline(cin,str)) return false;
    stringstream ss;
    ss<<str;
    int x;
    while(ss>>x) a[n++]=x;
    return n>0;
}
//深度优先找到权值最小的
int best,best_sum;

void dfs(int u,int sum)
{
    sum+=u;
    if(!lch[u]&&!rch[u]){
        if(sum<best_sum||(u<best&&sum==best_sum)){
            best=u;
            best_sum=sum;
        }
    }
    if(lch[u]) dfs(lch[u],sum);
    if(rch[u]) dfs(rch[u],sum);
}

int main()
{
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif

    while (read_input(inorder))
    {
        read_input(postorder);
        build_tree(0,n-1,0,n-1);
        best_sum=(int)1e9;
        dfs(postorder[n-1],0);
        cout<<best<<endl;
    }
    

    return 0;
}