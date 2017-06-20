#include <bits/stdc++.h>
namespace p1073{
using namespace std;
int father[5001],n,m,p,mi,mj;
int get(int p){
    if(father[p]==p)return p;
    father[p]=get(father[p]);
    return father[p];
}
int main(){
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&mi,&mj);
        // if(get(mi)!=get(mj)){
            father[get(mj)]=get(mi);
        // }
    }
    for(int i=0;i<p;i++){
        scanf("%d %d",&mi,&mj);
        if(get(mi)==get(mj))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
}
