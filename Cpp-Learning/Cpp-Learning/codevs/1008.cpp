#include<iostream>
namespace p1008{
int n,k,a=0,ns[25];
void check(int s){
    if(s<2)return;
    for(int i=2;i*i<=s;i++){
        if(s%i==0)return;
    }
    a++;
}
void dfs(int depth,int sum,int last){
    if(depth-1==k){
        check(sum);
        return;
    }
    for(int i=last+1;i<=n;i++){
        dfs(depth+1,ns[i]+sum,i);
    }
}
int main(){
    std::cin>>n>>k;
    for(int i=1;i<=n;i++)
        std::cin>>ns[i];
    dfs(1,0,0);
    std::cout<<a;
    return 0;
}
}
