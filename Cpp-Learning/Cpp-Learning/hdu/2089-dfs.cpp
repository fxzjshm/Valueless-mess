#include<bits/stdc++.h>
using namespace std;
namespace ph2089_dfs{
int dp[10][2],d[10];
int dfs(int len,bool state,bool ismax){
	if(len==0)return 1;
	if(!ismax&&dp[len][state]!=-1)return dp[len][state];
	int ret=0,maxn=(ismax)?(d[len]):(9);
	// cout<<len<<' '<<state<<' '<<ismax<<' '<<maxn<<endl;
	for(int i=0;i<=maxn;i++){
		if(i==4)continue;
		if(state&&i==2)continue;
		ret+=dfs(len-1,i==6,ismax&&(i==maxn));
	}
	if(!ismax)dp[len][state]=ret;
	return ret;
}
int work(int i){
	memset(dp,-1,sizeof(dp));
	memset(d,0,sizeof(d));
	int len=1;
	for(;i;len++){
		d[len]=i%10;
		i/=10;
	}
	return dfs(len,false,true);
}
int main(){
	int n,m;
	while(1){
	cin>>n>>m;
	if(n==0&&m==0)break;
	cout<<work(m)-work(n-1)<<endl;
	}
	return 0;
}
}
