#include <bits/stdc++.h>
using namespace std;
namespace p1501{
int n,ch[20][2],co[20],md=0,mw=0;
void dfs(int depth,int id){
    md=max(md,depth);
    co[depth]++;
    for(int i=0;i<2;i++){
        if(ch[id][i])dfs(depth+1,ch[id][i]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ch[i][0]>>ch[i][1];
    }
    dfs(1,1);
    for(int i=1;i<=md;i++){
        mw=max(mw,co[i]);
    }
    cout<<mw<<' '<<md;
    return 0;
}
}
