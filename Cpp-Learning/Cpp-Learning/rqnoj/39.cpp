#include<iostream>
using namespace std;
namespace pr39{
int dp[35005],C,B,v;
int main(){
	cin>>C>>B;
	for(int i=0;i<B;i++){
		cin>>v;
		for(int j=C;j>=v;j--){
			dp[j]=max(dp[j],dp[j-v]+v);
		}
	}
	cout<<dp[C];
	return 0;
}
}
