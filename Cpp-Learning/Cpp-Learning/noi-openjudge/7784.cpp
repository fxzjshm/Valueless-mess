#include <bits/stdc++.h>
using namespace std;
namespace p7784{
int main(){
    // while(1){
    unsigned long long n,t;
    cin>>n;
    while(n!=1){
        if(n&1){
            t=n*3+1;
            printf("%lld*3+1=%lld\n",n,t);
        }else{
            t=n/2;
            printf("%lld/2=%lld\n",n,t);
        }
        n=t;
    }
    cout<<"End"<<endl;
    // }
    return 0;
}
}
