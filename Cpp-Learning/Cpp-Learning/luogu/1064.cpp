#include<iostream>
using namespace std;
namespace pl1064{
struct{
	int v,vw,v1,vw1,v2,vw2;
}good[65];
int n,m,v,p,q,dp[32005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>v>>p>>q;
		int vw=v*p;
		if(q){
			if(good[q].v1){
				good[q].v2=v;
				good[q].vw2=vw;
			}else{
				good[q].v1=v;
				good[q].vw1=vw;
			}
		}else{
			good[i].v=v;
			good[i].vw=vw;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=good[i].v;j--){
			dp[j]=max(dp[j],dp[j-good[i].v]+good[i].vw);
			if(j-good[i].v>=good[i].v1)dp[j]=max(dp[j],dp[j-good[i].v-good[i].v1]+good[i].vw+good[i].vw1);
			if(j-good[i].v>=good[i].v2)dp[j]=max(dp[j],dp[j-good[i].v-good[i].v2]+good[i].vw+good[i].vw2);
			if(j-good[i].v>=good[i].v1+good[i].v2)
				dp[j]=max(dp[j],dp[j-good[i].v-good[i].v1-good[i].v2]+good[i].vw+good[i].vw1+good[i].vw2);
		}
	}
	cout<<dp[n];
	return 0;
}
}
