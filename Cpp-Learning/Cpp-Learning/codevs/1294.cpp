#include<iostream>
#include<cstdio>
using namespace std;
namespace p1294{
int n,used[11],a[11];
void print(){
	for(int i=1;i<n;i++)
		// cout<<a[i]<<' ';
		printf("%d",a[i]);
	// cout<<a[n]<<endl;
	printf("%d\n",a[n]);
}
void dfs(int depth){
	if(depth==n+1)print();
	else{
		for(int i=1;i<=n;i++){
			if(!used[i]){
				a[depth]=i;
				used[i]=1;
				dfs(depth+1);
				used[i]=0;
				}
			}
		}
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}
}
