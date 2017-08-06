#include<iostream>
#include<cstdio>
using namespace std;
namespace p2194{
int c1[15],c2[32],c3[32],n,ans[15],a=0;
void print(){
	a++;
	if(a<=3){
		for(int i=1;i<n;i++){
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
	}
}
void dfs(int depth){
	if(depth==n+1)print();
	for(int i=1;i<=n;i++){
		if(c1[i]==0&&c2[i+depth]==0&&c3[i-depth+n]==0){
			c1[i]=1;
			c2[i+depth]=1;
			c3[i-depth+n]=1;
			ans[depth]=i;
			dfs(depth+1);
			c1[i]=0;
			c2[i+depth]=0;
			c3[i-depth+n]=0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<a;
	return 0;
}
}
