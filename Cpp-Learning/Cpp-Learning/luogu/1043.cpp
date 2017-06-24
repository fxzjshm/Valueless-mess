#include<iostream>
using namespace std;
namespace pl1043{
int n,m,sum[105],dp[10][51][51];
int main(){
	cin>>n>>m;
	for(int i=1;i<=2*n;i++){
		cin>>sum[i];
		dp[0][i][i]=sum[i]%10;
		sum[i]+=sum[i-1];
	}
	for(int mi=2;mi<=m;m++){
		for(int s=1;s<=n;s++){
			for(int e=s+1;e<=n;e++){
				for(int t=s+1;t<e;t++){
					dp[mi][s][e]=min(dp[mi][s][e],(dp[mi-1][s][t]+sum[e]-sum[t-1])%10);
				}
			}
		}
	}
	cout<<dp[m][1][n]<<endl;
	return 0;
}
}
