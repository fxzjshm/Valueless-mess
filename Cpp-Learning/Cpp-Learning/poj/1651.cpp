#include<iostream>
namespace pp1651{
const int maxn=105,inf=0x3FFFFFFF;
int ns[maxn],n,dp[maxn][maxn];
int main(){
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>ns[i];
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			else dp[i][j]=inf;
		}
	}
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n;i++){
			int j=i+r-1;
			for(int k=i;k<j;k++){
				dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k+1][j]+ns[i-1]*ns[k]*ns[j]);
			}
		}
	}
	std::cout<<dp[2][n];
	return 0;
}
}
