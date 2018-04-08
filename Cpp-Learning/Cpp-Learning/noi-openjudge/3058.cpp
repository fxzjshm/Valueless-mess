#include <bits/stdc++.h>
namespace pnoi3058{
using namespace std;
const long long maxh=1000000005L;
struct c{
    long long h,i;
};
vector<c> cs;
stack<c> stk;
int main(){
    long long n;
    long long ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        c ci;
        cin>>ci.h;
        ci.i=i;
        cs.push_back(ci);
    }
    c cmax;
    cmax.h=maxh;
    cmax.i=n+1;
    cs.push_back(cmax);
    stk.push(cmax);
    int l=cs.size();
    for(int i=l-1;i>=0;i--){
        if(!stk.empty()&&cs[i].h>stk.top().h){
            // c cl;
            while(!stk.empty()&&stk.top().h<cs[i].h){
                // cl=stk.top();
                stk.pop();
            }
            // cout<<i+1<<' '<<stk.top().i-cs[i].i-1<<endl;
            // ans+=cl.i-cs[i].i;
            ans+=stk.top().i-cs[i].i-1;
        }
        stk.push(cs[i]);
    }
    cout<<ans;
    return 0;
}
}
