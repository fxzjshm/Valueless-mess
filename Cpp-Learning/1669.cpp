#include<cstdio>
inline int max(int a,int b){
	return (a>b)?a:b;
}
int v,g,n,ti,vi,gi,dp[1005][1005],maxn=0;
int main(){
	scanf("%d%d%d",&v,&g,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&ti,&vi,&gi);
		for(int j=g;j>=gi;j--){
			for(int k=v;k>=vi;k--){
				dp[j][k]=max(dp[j][k],dp[j-gi][k-vi]+ti);
				maxn=max(maxn,dp[j][k]);
			}
		}
	}
	printf("%d",maxn);
	return 0;
}
