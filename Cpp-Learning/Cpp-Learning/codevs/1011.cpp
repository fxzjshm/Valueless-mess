#include<iostream>
namespace p1011{
int n,a=0;
void dfs(int t){
	a++;
	for(int i=1;i<=t/2;i++){
	    dfs(i);
	}
}
int main(){
	std::cin>>n;
	dfs(n);
	std::cout<<a;
	return 0;
}
}
