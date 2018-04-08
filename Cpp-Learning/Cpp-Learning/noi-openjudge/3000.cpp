// WA
#include <bits/stdc++.h>
namespace pnoi3000{
using namespace std;
const int maxn=105;
struct st{
    string name;
    int mk;
};
bool operator<(st s1,st s2){
    return s1.name<s2.name;
}
st ns[maxn];
map<int,bool> mp;
vector<st> sts;
int main(){
    int T,n,t;
    scanf("%d",&T);
    while(T--){
        mp.clear();
        sts.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>ns[i].name;
            scanf("%d",&(ns[i].mk));
            for(int j=1;j<i;j++){
                mp[ns[i].mk+ns[j].mk]=1;
                for(int k=1;k<j;k++){
                    mp[ns[i].mk+ns[j].mk+ns[k].mk]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(mp[ns[i].mk])sts.push_back(ns[i]);
        }
        sort(sts.begin(),sts.end());
        int l=sts.size();
        printf("%d\n",l);
        for(int i=0;i<l;i++){
            cout<<sts[i].name<<endl;
        }
    }
    return 0;
}
}
