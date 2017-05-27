#include <bits/stdc++.h>
namespace p5709{
using namespace std;
int s,n,w[1005],k[1005],f[5005];
int main5709(){
    cin>>s>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>k[i];
        f[i]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=s;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+k[i]);
    cout<<f[s];
    return 0;
}
}
