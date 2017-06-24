#include<iostream>
using namespace std;
namespace pb1087{
int n,k,c1[1<<9],c2[1<<9][1<<9];
long long dp[10][82][1<<9],ans; // **** ***!
inline int getkn(int t){
	int s=0;
	while(t){
		s+=t&1;
		t>>=1;
	}
	return s;
}
inline bool check1(int i,int j){
	return (((i<<1)&j)==0)&&(((j<<1)&i)==0);
}
inline bool check2(int i,int j){
	return check1(i,j)&&((i&j)==0);
}
int main(){
	cin>>n>>k;
	int n1;
	for(int i=0;i<(1<<(n));i++){
		n1=getkn(i);
		if(n1<=k&&check1(i,i)){
			c1[i]=n1;
			dp[1][n1][i]=1;
		}
	}
	for(int i=0;i<(1<<n);i++){
		if(c1[i]||i==0){
			for(int j=0;j<(1<<n);j++){
				if(c1[j]||j==0){
					if(check2(i,j)){
						c2[i][j]=1;
					}
				}
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=0;i<(1<<n);i++){// last line
			int ni=c1[i];
			if(ni||i==0){
				for(int j=0;j<(1<<n);j++){// this line
					int nj=c1[j];
					if(nj||j==0){
						if(c2[i][j]){
							for(int p=ni+nj;p<=k;p++){
								dp[l][p][j]+=dp[l-1][p-nj][i];
							}
						}
					}
				}
			}
		}
	}
	/*for(int l=0;l<=n;l++){
		cout<<l<<':'<<endl;
		for(int p=0;p<=k;p++){
			for(int i=0;i<(1<<n);i++){
				cout<<dp[l][p][i]<<' ';
			}
			cout<<endl;
		}
	}*/
	for(int i=0;i<(1<<n);i++){
		ans+=dp[n][k][i];
	}
	cout<<ans;
	return 0;
}
}
