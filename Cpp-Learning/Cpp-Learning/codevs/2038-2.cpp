// floyd
#include<bits/stdc++.h>
using namespace std;
namespace p2038_2{
int dis[801][801],n,p,c,sd[801],f2c[801],mind=0x7f7f7f7f;
int main(){
	scanf("%d%d%d",&n,&p,&c);
	int t;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		f2c[t]++;
	}
	memset(dis,0x3f,sizeof(dis));
	int a,b,d;
	for(int i=1;i<=p;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=c;i++){
		scanf("%d%d%d",&a,&b,&d);
		dis[a][b]=min(dis[a][b],d);
		dis[b][a]=min(dis[b][a],d);
	}
	for(int k=1;k<=p;k++){
		for(int i=1;i<=p;i++){
			for(int j=1;j<=p;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p;j++){
			sd[i]+=dis[j][i]*f2c[j];
		}
		mind=min(mind,sd[i]);
	}
	printf("%d",mind);
	/*
	cout<<endl;
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	return 0;
}
}
