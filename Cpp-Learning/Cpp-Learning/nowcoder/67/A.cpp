#include<iostream>
#include<cstdio>
#include<vector>
namespace nowcoder_67A{
using namespace std;
const int maxn=100005;
int power[maxn];
vector<int> its[maxn];
double itms[maxn],ans;
int main(){
    int n,m;
    while(cin>>n){
        cin>>m;
        ans=-1;
        for(int i=1;i<=m;i++){
            itms[i]=0;
        }
        for(int i=1;i<=n;i++){
            its[i].clear();
            cin>>power[i];
            int s,t;
            cin>>t;
            for(int j=0;j<t;j++){
                cin>>s;
                its[i].push_back(s);
            }
        }
        int s,itn;
        double t;
        for(int i=1;i<=m;i++){
            cin>>s>>t;
            itn=max(itn,s);
            itms[s]=max(t,itms[s]);
        }
        for(int i=1;i<=n;i++){
            double time=1;
            for(int j=0;j<its[i].size();j++){
                time+=itms[its[i][j]];
            }
            ans=max(ans,power[i]*time);
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
}
/*int main(){
    return nowcoder_67A::main();
}*/
