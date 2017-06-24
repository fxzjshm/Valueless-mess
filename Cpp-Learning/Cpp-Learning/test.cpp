/*
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 13
#define M (1<<N)
#define mod  100000000
int st[M],ma[N];
int dp[N][M];
bool C(int x)
{
	return x&(x<<1);
}
bool can(int x,int y)
{
	return x&y;
}
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int aa;
			scanf("%d",&aa);
			if(!aa)ma[i]+=(1<<(j-1));
			}
	int k=0;
	for(int i=0;i<(1<<m);i++)
		if(!C(i))    st[++k]=i;
	for(int i=1;i<=k;i++)
		if(!can(st[i],ma[1]))   dp[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++){
			if(can(ma[i],st[j])) continue;
			for(int p=1;p<=k;p++)//枚举上一层的状态
			if(!can(ma[i-1],st[p])&&!can(st[j],st[p]))
			dp[i][j]+=dp[i-1][p];
			}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=dp[n][i];
		ans%=mod;
		}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            printf("%d",dp[i][j]);
        }
        printf("\n");
    }
	printf("%d\n",ans);
}
*/
