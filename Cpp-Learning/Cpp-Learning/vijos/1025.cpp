#include<iostream>
using namespace std;
namespace pv1025{
int dp[35005],C,B,v,t;
int main(){
	cin>>B>>C;
	for(int i=0;i<B;i++){
		cin>>v>>t;
		for(int j=C;j>=t;j--){
			dp[j]=max(dp[j],dp[j-t]+v);
		}
	}
	cout<<dp[C];
	return 0;
}
}
