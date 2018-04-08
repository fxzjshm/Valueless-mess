#include <bits/stdc++.h>
namespace pnoi3031{
using namespace std;
long long n,ans=0;
int main(){
    cin>>n;
    for(long long z=0;z*z*z<=n;z++){
        long long le=n-z*z*z;
        ans+=floor(sqrt(le)+1);
    }
    cout<<ans;
    return 0;
}
}
