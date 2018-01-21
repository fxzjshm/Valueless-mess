#include<iostream>
using namespace std;
namespace nowcoder_67I{
const int maxn=100000;
bool figc[10];
inline void apply(int x){
    while(x){
        figc[x%10]=false;
        x/=10;
    }
}
inline bool c1(int x){
    while(x){
        if(figc[x%10]){
            x/=10;
        }else return false;
    }
    return true;
}
int main(){
    int T,a,b,ans;
    cin>>T;
    for(int t=1;t<=T;t++){
        ans=0;
        for(int i=0;i<10;i++){
            figc[i]=true;
        }
        cin>>a>>b;
        apply(a);
        apply(b);
        for(int i=1;i<=1000;i++){
            if(i%a&&i%b&&c1(i))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
}
/*int main(){
    return nowcoder_67I::main();
}*/
