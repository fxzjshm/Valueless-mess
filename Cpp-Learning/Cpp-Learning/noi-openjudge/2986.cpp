#include <bits/stdc++.h>
using namespace std;
namespace p2986{
vector<int> as,bs;
int main(){
    int n,t;
    while(cin>>n){
        if(!n)break;
        as.clear();
        bs.clear();
        for(int i=1;i<=n;i++){
            cin>>t;
            as.push_back(t);
        }
        sort(as.begin(),as.end());
        for(int i=1;i<=n;i++){
            cin>>t;
            bs.push_back(t);
        }
        sort(bs.begin(),bs.end());
        int i=0,ans1=0,ans2=0;
        for(int j=0;j<=n;j++){

        }
    }
    return 0;
}
}
