#include<cstdio>
#include<cstring>
// #include<iostream>
#include<vector>
namespace pnoi1807{
using namespace std;
const int maxn=20005;
struct pt{
	int x,y;
}pts[maxn];
bool used[maxn];
pt box[maxn];
int n,ans;
inline int hs(pt p){
	return (p.x*p.x+p.y*p.y)%maxn;
}
inline bool ck(pt p){
	int t=hs(p);
	while(used[t]&&(box[t].x!=p.x||box[t].y!=p.y)){
		t++;
		t%=maxn;
	}
	return used[t];
}
int main(){
	while(scanf("%d",&n)&&n){
		ans=0;
		memset(pts,0,sizeof(pts));
		for(int i=1;i<=n;i++){
			pt p;
			scanf("%d%d",&p.x,&p.y);
			pts[i]=p;
			int t=hs(p);
			while(used[t])t++;
			box[t]=p;
			used[t]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				pt p1=pts[i],p2=pts[j],p3,p4;
				int dx=p1.x-p2.x,dy=p1.y-p2.y;
				p3.x=p2.x+dy;
				p3.y=p2.y-dx;
				p4.x=p1.x+dy;
				p4.y=p1.y-dx;
				if(ck(p3)&&ck(p4)){
					ans++;
					// printf("%d,%d %d,%d %d,%d %d,%d\n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
				}
				p3.x=p2.x-dy;
				p3.y=p2.y+dx;
				p4.x=p1.x-dy;
				p4.y=p1.y+dx;
				if(ck(p3)&&ck(p4)){
					ans++;
					// printf("%d,%d %d,%d %d,%d %d,%d\n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
				}
			}
		}
		printf("%d\n",ans/4);
	}
	return 0;
}
}
