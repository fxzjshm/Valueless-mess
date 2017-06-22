#include<iostream>
using namespace std;
namespace p1115{
int dp[300005],n,m,v,p;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>v>>p;
		for(int j=n;j>=v;j--){
			dp[j]=max(dp[j],dp[j-v]+v*p);
		}
	}
	cout<<dp[n];
	return 0;
}
}
