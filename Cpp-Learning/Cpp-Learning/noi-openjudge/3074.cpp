#include <bits/stdc++.h>
namespace pnoi3074{
using namespace std;
struct people{
    int k,p;
};
deque<people> peos;
int main(){
    int q,k,p;
    while(scanf("%d",&q)&&q!=0){
        if(q==1){
            people peo;
            scanf("%d%d",&peo.k,&peo.p);
            int l=0,r=peos.size(),mid;
            while(l<r){
                mid=((l+r)>>1);
                if(peos[mid].p>peo.p)l=mid+1;
                else r=mid;
            }
            peos.insert(peos.begin()+l,peo);
        }else if(q==2){
            if(peos.size()==0)printf("0\n");
            else{
                printf("%d\n",peos.front().k);
                peos.pop_front();
            }
        }else if(q==3){
            if(peos.size()==0)printf("0\n");
            else{
                printf("%d\n",peos.back().k);
                peos.pop_back();
            }
        }
        /*for(int i=0;i<peos.size();i++){
            cout<<(peos[i].p)<<' ';
        }
        cout<<endl;*/
    }
    return 0;
}
}
