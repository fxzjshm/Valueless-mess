#include<bits/stdc++.h>
using namespace std;
namespace pr343{
int f[20001],n,m,p,c[20001],maxn=0;
int g(int x){
	if(f[x]!=x)f[x]=g(f[x]);
	return f[x];
}
inline void u(int a,int b){
	if(g(a)!=g(b))f[g(b)]=g(a);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		u(a,b);
	}
	for(int i=1;i<=n;i++){
		g(i);
		c[f[i]]++;
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,c[i]);
	}
	cout<<maxn;
	return 0;
}
}
