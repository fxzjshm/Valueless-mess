#include<iostream>
using namespace std;
namespace nowcoder_67H{
const int maxn=85;
unsigned long long dp[maxn];
int cal(){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<maxn;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    /*for(int i=0;i<maxn;i++){
        cout<<dp[i]<<',';
    }*/
    return 0;
}
int main(){
    cal();
    int s,t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>s;
        cout<<dp[s]<<endl;
    }
    return 0;
}
}
/*int main(){
    return nowcoder_67H::main();
}*/
