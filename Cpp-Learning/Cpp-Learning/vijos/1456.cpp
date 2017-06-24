#include<cstdio>
#include<memory.h>
//#include<bits/stdc++.h>
//using namespace std;
namespace pv1456{
int n,edge[17][17],dp[1<<16][17],ans=0x3FFFFFFF;
inline int min(int a,int b){
	// if(a>0x3f3f3f3e&&b>0x3f3f3f3e)cout<<"Err!"<<endl;
	if(a>0x3f3f3f3e)return b;
	if(b>0x3f3f3f3e)return a;
	return (a<b)?a:b;
}
inline int jg(int state,int people){
	return (state)&(1<<people);
}
inline int un(int state,int people){
	return (state)|(1<<people);
}
int main(){
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&edge[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		dp[1<<i][i]=0;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(jg(i,j)){
				for(int k=0;k<n;k++){
					if(!jg(i,k)){
						int i2=un(i,k);
						// cout<<i<<' '<<j<<' '<<k<<' '<<i2<<endl;
						dp[i2][k]=min(dp[i2][k],dp[i][j]+edge[j][k]);
						if(i2==(1<<n)-1)ans=min(ans,dp[i2][k]);
					}
				}
			}
		}
	}
	/*for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	printf("%d",ans);
	return 0;
}
}
