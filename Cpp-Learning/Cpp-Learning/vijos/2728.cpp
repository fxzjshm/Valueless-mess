#include<iostream>
#include<memory.h>
using namespace std;
namespace pv2728{
long long dp[300005],n,m,ai,bi;
inline long long min(long long a,long long b){
	return (a<b)?a:b;
}
inline long long pow(long long a,long long s){
	long long t=1;
	for(;s;s--)t*=a;
	return t;
}
int main(){
	cin>>n>>m;
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<m;i++){
		cin>>ai>>bi;
		for(int j=n;j>0;j--){
			for(int k=0;k<=j;k++){
				dp[j]=min(dp[j],dp[j-k]+ai*pow(k,bi));
			}
		}
	}
	cout<<dp[n];
	return 0;
}
}
