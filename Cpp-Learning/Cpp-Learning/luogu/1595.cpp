#include<iostream>
namespace pl1595{
int n,a=0,used[10000005];
void dfs(int depth){
	if(depth-1==n){
		a++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&i!=depth){
			used[i]=1;
			dfs(depth+1);
			used[i]=0;
		}
	}
}
int main(){
	std::cin>>n;
	dfs(1);
	std::cout<<a;
	return 0;
}
}
