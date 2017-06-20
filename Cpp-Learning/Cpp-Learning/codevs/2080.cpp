//----BUGGY--------------
#include<cstdio>
namespace p2080{
int n1[4]={2,3,5,7},n2[4]={1,3,7,9},n;
bool check(int t){
    if(t<2)return false;
    for(int i=2;i*i<=t;i++){
        if(t%i==0)return false;
    }
    return true;
}
void dfs(int depth,int sum){
    int t=sum/10;
    if(depth==n+1){
        if(check(t))
            printf("%d\n",t);
        return;
    }
    for(int i=0;i<4;i++){
        t=sum+n2[i];
        if(check(i)){
            dfs(depth+1,t*10);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        dfs(2,n1[i]*10);
    }
    return 0;
}
}
int main(){
    p2080::main();
    return 0;
}
