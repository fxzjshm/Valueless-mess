#include <bits/stdc++.h>
using namespace std;
namespace pnoi2983{
vector<int> ns;
map<int,int> mp;
int n,m,t,s;
int main(){
    cin>>n>>m;
    ns.push_back(-1);
    for(int i=1;i<=n;i++){
        cin>>t;
        ns.push_back(t);
        mp[t]++;
    }
    for(int i=1;i<ns.size();i++){
        s=mp[ns[i]]-1;
        if(s)cout<<s<<endl;
        else cout<<"BeiJu"<<endl;
    }
    return 0;
}
}
