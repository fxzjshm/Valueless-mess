#include <bits/stdc++.h>
using namespace std;
namespace pnoi2454{
const int maxn=2005;
unsigned int dp[maxn][maxn],dp2[maxn],fs[maxn][maxn];
int n,h,d;
int main(){
    memset(fs,0,sizeof(fs));
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    scanf("%d%d%d",&n,&h,&d);
    int ni,hi;
    for(int i=1;i<=n;i++){
        scanf("%d",&ni);
        for(int j=1;j<=ni;j++){
            scanf("%d",&hi);
            fs[i][hi]++;
        }
    }

    for(int k=h;k>=0;k--){
    	if(k+d<=h){
            for(int i=1;i<=n;i++){
                dp2[k+d]=max(dp2[k+d],dp[k+d][i]);
                // cout<<k+d<<' '<<dp2[k+d]<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            dp[k][i]=max(((k+1<=h)?(dp[k+1][i]):(0)),((k+d<=h)?(dp2[k+d]):(0)));
            dp[k][i]+=fs[i][k];
            // cout<<k<<' '<<i<<' '<<dp[k][i]<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        dp2[0]=max(dp2[0],dp[0][i]);
    }
    printf("%d",dp2[0]);
    return 0;
}
}
