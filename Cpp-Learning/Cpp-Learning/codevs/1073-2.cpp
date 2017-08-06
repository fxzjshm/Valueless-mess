#include<bits/stdc++.h>
using namespace std;
namespace p1073_2{
int f[20001],n,m,p;
int g(int x){
	if(f[x]!=x)f[x]=g(f[x]);
	return f[x];
}
inline void u(int a,int b){
	if(g(a)!=g(b))f[g(b)]=g(a);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		u(a,b);
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d",&a,&b);
		printf((g(a)==g(b))?"Yes\n":"No\n");
	}
	return 0;
}
}
