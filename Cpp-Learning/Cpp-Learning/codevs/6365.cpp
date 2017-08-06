#include<bits/stdc++.h>
using namespace std;
namespace p6365{
long long n,t,l,r;
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&t);
        t=abs(t);
        l=0,r=t;
        while(l<r){
            long long mid=(l+r)>>1;
            if(mid*mid>=t)r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
}
