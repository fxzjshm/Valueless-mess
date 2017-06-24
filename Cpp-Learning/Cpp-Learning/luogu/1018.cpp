#include<iostream>
using namespace std;
namespace pl1018{
long long n,k1,/*num[45],*/cache[45][45],dp[/* luogu=7, rqnoj=*/35][45];
int main(){
	cin>>n>>k1;
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		// num[i]=c-'0';
		cache[i][i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cache[i][j]=cache[i][j-1]*10+cache[j][j];
		}
	}
	for(int i=1;i<=n;i++){
		dp[0][i]=cache[1][i];
	}
	for(int k=1;k<=k1;k++){// * count
		for(int i=1;i<=n;i++){// length
			for(int j=k+1;j<=i;j++){// breakpoint
				dp[k][i]=max(dp[k][i],dp[k-1][j-1]*cache[j][i]);
			}
		}
	}
	cout<<dp[k1][n];
	return 0;
}
}
