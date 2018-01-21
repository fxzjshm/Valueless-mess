#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
namespace nowcoder_67G{
const int maxn=2188;
char c[maxn][maxn];
int line[maxn],sz;
inline int power(int x,int y){
    int ret=1;
    for(int i=1;i<=y;i++)ret*=x;
    return ret;
}
void dfs(int dep,int x,int y){
    if(dep==0){
        c[x][y]='O';
        line[x]=max(y,line[x]);
        sz=max(x,sz);
        return;
    }
    int delta=power(3,dep-1);
    dfs(dep-1,x+delta,y);
    dfs(dep-1,x,y+delta);
    dfs(dep-1,x+delta*2,y+delta);
    dfs(dep-1,x+delta,y+delta*2);
}
int main(){
    int T,n;
    cin>>T;
    for(int T1=1;T1<=T;T1++){
        memset(c,' ',sizeof(c));
        memset(line,0,sizeof(line));
        sz=0;
        cin>>n;
        dfs(n,0,0);
        for(int i=0;i<=sz;i++){
            for(int j=0;j<=line[i];j++){
                printf("%c",c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
}
/*int main(){
    return nowcoder_67G::main();
}*/
