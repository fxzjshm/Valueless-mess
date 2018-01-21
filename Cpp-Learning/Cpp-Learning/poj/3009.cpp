#include<cstdio>
#include<iostream>
namespace poj3009{
	const int maxn=22;
	const int dx[4]={0,1,0,-1};
	const int dy[4]={1,0,-1,0};
	int mp[maxn][maxn],w,h,ans=-1;
	struct pt{
		int x,y;
	};
	pt st,ed;
	void dfs(const int x,const int y,const int deplim,const int depth){
		// printf("[DEBUG]dfs(x=%d,y=%d,deplim=%d.depth=%d)\n",x,y,deplim,depth);
		if(depth>deplim||ans!=-1)return;
		int x2,y2,x3,y3;
		for(int k=0;k<=3;k++){
			x2=x,y2=y;
			if(mp[x2+dx[k]][y2+dy[k]]==1)continue;
			while(true){
				x2+=dx[k];
				y2+=dy[k];
				if(x2<1||x2>h||y2<1||y2>w)goto ABT;
				else if(mp[x2][y2]==1){
					x3=x2;
					y3=y2;
					x2-=dx[k];
					y2-=dy[k];
					break;
				}else if(mp[x2][y2]==3){
					ans=depth;
					// printf("[DEBUG]answer find: x=%d y=%d mp[x][y]=%d\n",x2,y2,mp[x2][y2]);
					return;
				}
			}
			if(x2==x&&y2==y)return;
			else{
				mp[x3][y3]=0;
				dfs(x2,y2,deplim,depth+1);
				mp[x3][y3]=1;
				if(ans!=-1)return;
			}
			ABT:;
		}
	}
	int main(){
		while(~scanf("%d%d",&w,&h)){
			if(w==0&&h==0)return 0;
			for(int i=1;i<=h+1;i++){
				for(int j=1;j<=w+1;j++){
					mp[i][j]=0;
				}
			}
			ans=-1;
			for(int i=1;i<=h;i++){
				for(int j=1;j<=w;j++){
					scanf("%d",&mp[i][j]);
					if(mp[i][j]==2){
						st.x=i;
						st.y=j;
					}else if(mp[i][j]==3){
						ed.x=i;
						ed.y=j;
					}
				}
			}
			for(int deplim=1;deplim<=10&&ans==-1;deplim++){
				dfs(st.x,st.y,deplim,1);
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
