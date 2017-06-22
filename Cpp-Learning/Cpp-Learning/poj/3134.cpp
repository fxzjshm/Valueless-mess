// not completed!
#include<cstdio>
#include<memory.h>
namespace pp3134{
int deplim,n,f/*,ns[10000]*/,q=0,p;
void dfs(int depth,int t){
	if(depth>deplim)return;

}
int main(){
	while(1){
		scanf("%d",&n);
		// memset(ns,0,sizeof(ns));
		f=0;
		if(n==0)break;
		if(q)printf("\n");
		q=1;
		// ns[1]=1;
		// p=1;
		for(deplim=1;f==0;deplim++){
			dfs(1,n);
		}
		printf("%d\n",f);
	}
	return 0;
}
}
