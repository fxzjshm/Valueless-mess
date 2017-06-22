// not completed!
#include<cstdio>
#include<memory.h>
namespace ph2159{
inline int max(int a,int b){
	return (a>b)?a:b;
}
int dp[1005][1005],n,m,k,s,ni,mi,m2maxn[1005];
int main(){
	while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<k;i++){
			scanf("%d%d",&ni,&mi);
			for(int t=mi;t<=m;t++){
				for(int j=1;j<=s;j++){

					dp[j][t]=max(dp[j][t],dp[j-1][t-mi]+ni);
					m2maxn[t]=max(m2maxn[t],dp[j][t]);
				}
			}
		}
		for(int i=m;i>=0;i--){
			if(m2maxn[i]>=n){
				printf("T1:%d\n",m-i);
				goto L1;
			}
		}
		printf("T2:%d\n",-1);
		L1:;
	}
	return 0;
}
}
