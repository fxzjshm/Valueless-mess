// tle
#include <bits/stdc++.h>
using namespace std;
namespace pnoi2455{
const unsigned int maxn=(1<<31);
int maxp;
map<int,int> ns;
int main(){
    int T,n,s,e,d;
    scanf("%d",&T);
    while(T--){
        ns.clear();
        maxp=-1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&s,&e,&d);
            for(int j=s;j<=e;j+=d){
                ns[j]++;
            }
            maxp=max(maxp,e);
        }
        // cout<<"inputed"<<maxp<<endl;
        for(int i=0;i<=maxp;i++){
            if((ns[i]&1)){
                printf("%d %d\n",i,ns[i]);
                goto CO;
            }
        }
        printf("Poor QIN Teng:(\n");
        CO:continue;
    }
    return 0;
}
}
