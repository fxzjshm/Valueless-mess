#include<cstdio>
namespace pr49{
long long m[31],root[31][31],mark[31][31],n;
long long dfs(int a,int b){
	if(a>b)return 0;
	if(mark[a][b])return mark[a][b];
	long long mk=dfs(a+1,b)+m[a],m2;
	root[a][b]=a;
	for(int i=a+1;i<b;i++){
		m2=dfs(a,i-1)*dfs(i+1,b)+m[i];
		if(m2>mk){
			mk=m2;
			root[a][b]=i;
		}
	}
	m2=dfs(a,b-1)+m[b];
	if(m2>mk){
		mk=m2;
		root[a][b]=b;
	}
	mark[a][b]=mk;
	return mark[a][b];
}
void print(int a,int b){
	if(a>b)return;
	int rt=root[a][b];
	//cout<<rt<<' ';
	printf("%d ",rt);
	print(a,rt-1);
	print(rt+1,b);
}
int main(){
	//cin>>n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		//cin>>m[i];
		scanf("%lld",&m[i]);
		// root[i][i]=i;
	}
	dfs(1,n);
	// cout<<mark[1][n]<<endl;
	printf("%lld\n",mark[1][n]);
	print(1,n);
	return 0;
}
}
