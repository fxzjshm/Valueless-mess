#include<iostream>
using namespace std;
namespace p1068{
int n,m,score[400],card[5],t,dp[41][41][41][41];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>score[i];
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		card[t]++;
	}
	dp[0][0][0][0]=score[1];
	// for(int i=1;i<=m;i++){
	for(int a=0;a<=card[1];a++){
		for(int b=0;b<=card[2];b++){
			for(int c=0;c<=card[3];c++){
				for(int d=0;d<=card[4];d++){
					int step=1+a+2*b+3*c+4*d;
					int maxn=dp[a][b][c][d]-score[step];
					if(a>0){
						maxn=max(maxn,dp[a-1][b][c][d]);
					}
					if(b>0){
						maxn=max(maxn,dp[a][b-1][c][d]);
					}
					if(c>0){
						maxn=max(maxn,dp[a][b][c-1][d]);
					}
					if(d>0){
						maxn=max(maxn,dp[a][b][c][d-1]);
					}
					dp[a][b][c][d]=maxn+score[step];
				}
			}
		}
	}
	// }
	cout<<dp[card[1]][card[2]][card[3]][card[4]];
	return 0;
}
}
