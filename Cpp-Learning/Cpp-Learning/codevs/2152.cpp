#include<cstdio>
#include<algorithm>
using namespace std;
namespace p2152{
const int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
int map[105][105],r,c,dp[105][105],a=0;
inline bool check(int x,int y){
	return x>0&&y>0&&x<=r&&y<=c;
}
int dfs(int x,int y){
	if(check(x,y)){
		if(dp[x][y])return dp[x][y];
		dp[x][y]=1;
		int x1,y1;
		for(int i=0;i<4;i++){
			x1=x+dx[i];
			y1=y+dy[i];
			if(check(x1,y1)&&map[x1][y1]<map[x][y]){
				dp[x][y]=max(dp[x][y],dfs(x1,y1)+1);
			}
		}
		return dp[x][y];
	}
	else return 0;
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			a=max(a,dfs(i,j));
		}
	}
	printf("%d",a);
	return 0;
}
}
