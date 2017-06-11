#include <bits/stdc++.h>
namespace p1014{
using namespace std;
int f[20001],V,N,w;
int main1014(){
    cin>>V>>N;
    for(int i=1;i<=N;i++){
        cin>>w;
        for(int j=V;j>=w;j--)
            f[j]=max(f[j],f[j-w]+w);
    }
    cout<<V-f[V];
    return 0;
}
}
