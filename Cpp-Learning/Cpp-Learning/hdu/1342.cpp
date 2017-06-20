#include<cstdio>
namespace ph1342{
int a[7],n=6,k,ns[15],used[15],pd;
void print(){
    for(int i=1;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n]);
}
void dfs(int depth,int last){
    if(depth==n+1){
        print();
        return;
    }
    for(int i=last+1;i<=k;i++){
        used[i]=1;
        a[depth]=ns[i];
        dfs(depth+1,i);
        used[i]=0;
    }
}
int main(){
    while(1){
        scanf("%d",&k);
        if(k==0)return 0;
        if(pd)printf("\n");
        else pd=1;
        for(int i=1;i<=k;i++){
            scanf("%d",&ns[i]);
        }
        dfs(1,0);
    }
    return 0;
}
}
