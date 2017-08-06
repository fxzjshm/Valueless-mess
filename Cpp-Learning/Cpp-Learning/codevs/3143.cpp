#include <bits/stdc++.h>
using namespace std;
namespace p3143{
int n,ch[20][2],flag=-1;
void dfs(int depth,int id){
    if(flag==-1)printf("%d ",id);
    if(ch[id][0])dfs(depth+1,ch[id][0]);
    if(flag==0)printf("%d ",id);
    if(ch[id][1])dfs(depth+1,ch[id][1]);
    if(flag==1)printf("%d ",id);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ch[i][0]>>ch[i][1];
    }
    for(int i=1;i<=3;i++){
        dfs(1,1);
        printf("\n");
        flag++;
    }
    return 0;
}
}
