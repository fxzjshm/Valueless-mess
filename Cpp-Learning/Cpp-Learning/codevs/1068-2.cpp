#include<iostream>
#include<memory.h>
using namespace std;
namespace p1068_2{
int n,m,score[400],card[5],t,dp[41][41][41][41];
int dfs(int a,int b,int c,int d){
	int step=1+a+2*b+3*c+4*d;
	if(dp[a][b][c][d]>=0)return dp[a][b][c][d];
	int maxn=0;
	if(a>0)maxn=max(maxn,dfs(a-1,b,c,d));
	if(b>0)maxn=max(maxn,dfs(a,b-1,c,d));
	if(c>0)maxn=max(maxn,dfs(a,b,c-1,d));
	if(d>0)maxn=max(maxn,dfs(a,b,c,d-1));
	dp[a][b][c][d]=maxn+score[step];
	return dp[a][b][c][d];
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>score[i];
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		card[t]++;
	}
	dp[0][0][0][0]=score[1];
	cout<<dfs(card[1],card[2],card[3],card[4]);
	return 0;
}
}
