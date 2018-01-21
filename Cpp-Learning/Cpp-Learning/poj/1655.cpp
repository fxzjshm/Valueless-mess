#include<cstdio>
#include<vector>
const int maxn=20005;
int n,ans=maxn,no;
std::vector<int> rds[maxn];
int dfs(int x,int fa){
	int len=rds[x].size(),size=0,mn=0;
	for(int i=0;i<len;i++){
		int y=rds[x][i];
		if(y==fa)continue;
		int si=dfs(y,x);
		size+=si;
		mn=std::max(si,mn);
	}
	size+=1;
	int sf=n-size;
	mn=std::max(mn,sf);
	if(mn<ans){
		ans=mn;
		no=x;
	}else if(mn==ans){
		no=std::min(no,x);
	}
	return size;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			rds[i].clear();
		}
		ans=maxn;
		no=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			rds[u].push_back(v);
			rds[v].push_back(u);
		}
		dfs(1,-1);
		printf("%d %d\n",no,ans);
	}
	return 0;
}
