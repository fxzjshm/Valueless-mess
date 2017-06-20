#include <bits/stdc++.h>
namespace p1102{
using namespace std;
int f[1001],T,M,w,v;
int main(){
    cin>>T>>M;
    for(int i=0;i<M;i++){
        cin>>w>>v;
        for(int j=T;j>=w;j--)
            f[j]=max(f[j],f[j-w]+v);
    }
    cout<<f[T];
    return 0;
}
}
