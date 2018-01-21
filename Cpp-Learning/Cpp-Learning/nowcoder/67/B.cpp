#include<iostream>
using namespace std;
namespace nowcoder_67B{
const int maxn=100005;
struct card{
    int s,t,x;
}cs[maxn];
int main(){
    int n;
    unsigned long long ans;
    while(cin>>n){
        ans=0;
        for(int i=1;i<=n;i++){
            cs[i].s=0;
            cs[i].t=0;
            cs[i].x=0;
            cin>>cs[i].s>>cs[i].t;
            if(cs[i].t==1||cs[i].t==2){
                cin>>cs[i].x;
            }
        }
        int s=1,t;
        while(s<=n){
            for(int i=s;1;i++){
                if(i==n||cs[i+1].s<cs[i].s){
                    t=i;
                    break;
                }
            }
            // printf("s=%d,t=%d\n",s,t);
            for(int i=t;i>=s;i--){
                // printf("i=%d,ans=%d\n",i,ans);
                card ci=cs[i];
                if(ci.t==1){
                    ans+=ci.x;
                }else if(ci.t==2){
                    ans+=ci.x*(i-s+1);
                }else if(ci.t==3){
                    break;
                }else if(ci.t==4){
                    i--;
                }
                // printf("i=%d,ans=%d\n",i,ans);
            }
            s=t+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
}
/*int main(){
    return nowcoder_67B::main();
}*/
