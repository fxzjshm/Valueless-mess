#include<iostream>
#include<memory.h>
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
using namespace std;
namespace p3961{
int dp[100005],n,m,t;
int main(){
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=t;j<=m;j++){
			dp[j]=min(dp[j],dp[j-t]+1);
		}
	}
	cout<<dp[m];
	return 0;
}
}
