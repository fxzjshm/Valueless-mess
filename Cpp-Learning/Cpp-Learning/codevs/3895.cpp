#include<iostream>
#include<cstdio>
namespace p3895{
int n,a[12],used[12];
bool check(int s){
	if(s<2)return false;
	for(int i=2;i*i<=s;i++){
		if(s%i==0)return false;
	}
	return true;
}
void print(){
	for(int i=1;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n]);
}
void dfs(int depth){
	if(depth-1==n&&check(a[1]+a[n])){
		print();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&check(a[depth-1]+i)){
			a[depth]=i;
			used[i]=1;
			dfs(depth+1);
			used[i]=0;
		}
	}
}
int main(){
	std::cin>>n;
	if(n%2){
		std::cout<<"no";
		return 0;
	}
	a[1]=1;
	used[1]=1;
	dfs(2);
	return 0;
}
}
