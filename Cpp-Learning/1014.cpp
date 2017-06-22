#include<iostream>
using namespace std;
int v,n,t,dp[20005];
int main(){
	cin>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=v;j>=t;j--){
			dp[j]=max(dp[j],dp[j-t]+t);
		}
	}
	cout<<v-dp[v];
	return 0;
}
