#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
namespace pn6261{
void dfs(int i,char a,char b,char c){ // a---c--->b
	if(i>0){
		dfs(i-1,a,c,b);
		printf("%c->%d->%c\n",a,i,b);
		dfs(i-1,c,b,a);
	}
}
int main(){
	int n;
	char a,b,c;
	cin>>n>>a>>b>>c;
	dfs(n,a,b,c);
	return 0;
}
}
