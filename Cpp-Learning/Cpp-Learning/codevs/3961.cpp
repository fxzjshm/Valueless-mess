//---------BUGGY!---------------
#include <bits/stdc++.h>
namespace p3961{
using namespace std;
int f[100005],N,T,w;
int main3961(){
    memset(f,0x7F,sizeof(f));
    f[0]=0;
    cin>>N>>T;
    for(int i=0;i<N;i++){
        cin>>w;
        for(int j=T;j>=w;j--)
            f[j]=min(f[j],f[j-w]+1);
    }
    for(int i=T;i>0;i--){
        if(f[i]<0x7F7F7F7F){
            cout<<f[i];
            return 0;
        }
    }
    return 0;
}
}
