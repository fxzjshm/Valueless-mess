// not completed!
#include<cstdio>
#include<memory.h>
namespace ph2159{
inline int max(int a,int b){
	return (a>b)?a:b;
}
int dp[1005][1005],exp,bear,ntype,nmax,expi,beari,m2maxn[1005];
int main(){
	while(scanf("%d%d%d%d",&exp,&bear,&ntype,&nmax)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<ntype;i++){
			scanf("%d%d",&expi,&beari);
			for(int t=beari;t<=bear;t++){
				for(int j=1;j<=nmax;j++){

					dp[j][t]=max(dp[j][t],dp[j-1][t-beari]+expi);
					m2maxn[t]=max(m2maxn[t],dp[j][t]);
				}
			}
		}
		for(int i=bear;i>=0;i--){
			if(m2maxn[i]>=exp){
				printf("T1:%d\n",bear-i);
				goto L1;
			}
		}
		printf("T2:%d\n",-1);
		L1:;
	}
	return 0;
}
}
