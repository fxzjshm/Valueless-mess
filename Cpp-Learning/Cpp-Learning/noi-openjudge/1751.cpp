#include<iostream>
#include<memory.h>
using namespace std;
namespace pnoi1751{
int f[32769];
long long ans;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        memset(f,0,sizeof(f[40000]));
        ans=1;
        for(int i=2;i<32768;i++){
            L1:;
            if(!(t%i)){
                f[i]++;
                t/=i;
                goto L1;
            }
        }
        for(int i=2;i<32768;i++)
            ans*=f[i]+1;
        cout<<ans<<endl;
    }
}
}
