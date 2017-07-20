#include <bits/stdc++.h>
using namespace std;
namespace pnoi1809{
map<int,int> mp;
vector<int> ns;
int t,ans;
int main(){
    cin>>t;
    while(t){
        mp[t]=1;
        ns.push_back(t);
        cin>>t;
    }
    for(int i=0;i<ns.size();i++){
        if(mp[2*ns[i]])ans++;
    }
    cout<<ans;
    return 0;
}
}
