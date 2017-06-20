#include<cstdio>
namespace p2080{
int n1[4]={2,3,5,7},n2[4]={1,3,7,9},n;
bool check(int t){
    // printf("checking:%d\n",t);
    if(t<2)return false;
    for(int i=2;i*i<=t;i++){
        if(t%i==0)return false;
    }
    return true;
}
void dfs(int depth,int num){
    if(depth-1==n){
        if(check(num))printf("%d\n",num);
        return;
    }
    int t;
    for(int i=0;i<4;i++){
        t=num*10+n2[i];
        if(check(t))
            dfs(depth+1,t);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        dfs(2,n1[i]);
    }
    return 0;
}
}

