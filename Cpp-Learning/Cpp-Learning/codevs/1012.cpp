#include <bits/stdc++.h>
using namespace std;
namespace p1012{
long long gcd(long long a,long long b){
    return (b)?gcd(b,a%b):a;
}
int main(){
    long long x0,y0,m,ans=0,i,j;
    cin>>x0>>y0;
    if(x0>y0)swap(x0,y0);
    m=x0*y0;
    for(i=x0;i<=y0;i++){
        j=m/i;
        if(i*j!=m)continue;
        if(gcd(i,j)==x0)ans++;
    }
    cout<<ans;
    return 0;
}
}
