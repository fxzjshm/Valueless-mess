#include<iostream>
#include<cstdio>
using namespace std;
namespace p1039{
int n,k,a=0;
void dfs(int depth,int sum,int last){
	if(depth==k&&sum==n){
		a++;
		return;
	}
	if(depth==k||sum==n){
		return;
	}
	for(int i=last;i<=n-sum;i++){
		dfs(depth+1,sum+i,i);
	}
}
int main(){
	cin>>n>>k;
	dfs(0,0,1);
	cout<<a;
	return 0;
}
}
