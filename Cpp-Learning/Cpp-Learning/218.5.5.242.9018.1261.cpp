#include<cstdio>
using namespace std;
namespace p218_5_5_242_9018__1261{
int n,a[25];
void print(int depth){
	printf("%d=",n);
	for(int i=0;i<depth-1;i++){
		printf("%d+",a[i]);
	}
	printf("%d\n",a[depth-1]);
}
void dfs(int depth,int sum,int last){
	if(sum==n)print(depth);
	for(int i=last;i<=n-sum;i++){
		a[depth]=i;
		dfs(depth+1,sum+i,i);
	}
}
int main(){
	scanf("%d",&n);
	dfs(0,0,1);
}
}
