#include<iostream>
inline int max(int a,int b){
	return (a>b)?a:b;
}
int dp[1005],t,m,ti,vi;
int main(){
	std::cin>>t>>m;
	for(int i=1;i<=m;i++){
		std::cin>>ti>>vi;
		for(int j=t;j>=ti;j--){
			dp[j]=max(dp[j],dp[j-ti]+vi);
		}
	}
	std::cout<<dp[t];
	return 0;
}
