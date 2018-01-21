#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
namespace nowcoder_67E{
const int maxn=105;
int n,m,k,c,cd[maxn],used[maxn],used1[maxn];
unsigned long long ans;
int head[maxn],cnt=1;
struct rd{
    int u,v,e/*,w*/,next;
}rds[2*maxn];
inline void ins(int u,int v,int e){
    rd r;
    r.u=u;
    r.v=v;
    r.e=e;
    r.next=head[u];
    rds[cnt]=r;
    head[u]=cnt;
    cnt++;
}
void dfs(int x,unsigned long long cost){
    // printf("x=%d,cost=%d\n",x,cost);
    if(x==c){
        // cout<<cost<<endl;
        ans=min(ans,cost);
        return;
    }else{
        for(int i=head[x];i;i=rds[i].next){
            if(used1[rds[i].v])continue;
            if(used[rds[i].e]){
                dfs(rds[i].v,cost);
            }else{
                used[rds[i].e]=1;
                used1[rds[i].v]=1;
                dfs(rds[i].v,cost+cd[rds[i].e]);
                used[rds[i].e]=0;
                used1[rds[i].v]=0;
            }
        }
    }
}
int main(){
    while(cin>>n){
        cin>>m>>k>>c;
        ans=0;
        ans-=1;
        int u,v,w,e;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>e;
            ins(u,v,e);
        }
            int s,t;
        for(int i=1;i<=k;i++){
            cin>>s>>t;
            cd[s]=t;
        }
        /*for(int i=0;i<cnt;i++){
            rds[i].w=cd[rds[i].e];
        }*/
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
}
/*int main(){
    return nowcoder_67E::main();
}*/
