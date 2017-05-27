#include <bits/stdc++.h>
namespace p1540{
using namespace std;
struct ship{
    int father,nfront,ncount;
} ss[30001];
int get(int x){
    if(x==ss[x].father)return x;
    const int t=get(ss[x].father);
    if(t!=ss[x].father){
        ss[x].nfront+=ss[ss[x].father].nfront;
        ss[x].father=t;
    }
    return t;
}
void u(int x,int y){
    ss[ss[x].father].nfront=ss[y].ncount;
    ss[y].ncount+=ss[ss[x].father].ncount;
    ss[ss[x].father].father=y;
}
int main1540(){
    for(int i=1;i<30000;i++){
        ss[i].father=i;
        ss[i].nfront=0;
        ss[i].ncount=1;
    }
    int t,i,j;
    char s;
    cin>>t;
    for(int k=0;k<t;k++){
        scanf("%s%d%d",&s,&i,&j);
        if(s=='M'){
            if(get(i)!=get(j))
                u(i,j);
        }else{
            if(get(i)==get(j))printf("%d\n",abs(ss[i].nfront=ss[j].nfront)-1);
            else printf("-1\n");
        }
    }
    return 0;
}
}
