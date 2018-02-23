#include <bits/stdc++.h>
using namespace std;
namespace pnoi2728{
const int maxn=105;
int ns[maxn][maxn];
long long dp[maxn][maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(ns,0,sizeof(ns));
        memset(dp,0,sizeof(dp));
        int r,c;
        cin>>r>>c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>ns[i][j];
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+ns[i][j];
            }
        }
        cout<<dp[r][c]<<endl;
    }
    return 0;
}
}
