#include <bits/stdc++.h>
using namespace std;
namespace pnoi6184{
vector<int> ns;
int n,t,k;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>t;
        ns.push_back(t);
    }
    for(int i=0;i<ns.size();i++){
        for(int j=i+1;j<ns.size();j++){
            if(ns[i]+ns[j]==k){
                cout<<"yes";
                return 0;
            }
        }
    }
    cout<<"no";
    return 0;
}
}
