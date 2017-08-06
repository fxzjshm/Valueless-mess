#include<bits/stdc++.h>
using namespace std;
namespace pl2831{
struct pos{double x,y;};
struct poly{double a,b;};
int t,n,m,dp[(1<<20)],g[20][20];
vector<pos> pigs;
vector<poly> polys;
vector<int> tgss;
inline bool eq(double a,double b){
	return abs(a-b)<(0.000001);
}
void init(){
	pigs.clear();
	polys.clear();
	tgss.clear();
	memset(g,-1,sizeof(g));
	memset(dp,0x7f,sizeof(dp));
	double x1,y1;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++){
		scanf("%lf",&x1);
		scanf("%lf",&y1);
		pos p;
		p.x=x1;
		p.y=y1;
		pigs.push_back(p);
	}
}
void pre(){
	dp[0]=0;
	double x1,y1,x2,y2,a,b;
	int tg;
	for(int i=0;i<pigs.size();i++){
		x1=pigs[i].x,y1=pigs[i].y;
		for(int j=i+1;j<pigs.size();j++){
			x2=pigs[j].x,y2=pigs[j].y;
			if(eq(x1,x2))continue;
			a=(y1*x2-y2*x1)/(x1*x2*(x1-x2));
			if(a>=0)continue;
			b=(x1*x1*y2-x2*x2*y1)/(x1*x2*(x1-x2));
			poly p;
			p.a=a;
			p.b=b;
			for(int k=0;k<polys.size();k++){
				if(polys[k].a==a&&polys[k].b==b)goto E;
			}
			polys.push_back(p);
			g[j][i]=g[i][j]=polys.size()-1;
			tg=0;
			for(int l=0;l<pigs.size();l++){
				pos p=pigs[l];
				if(eq(a*p.x*p.x+b*p.x,p.y))tg|=(1<<l);
			}
			tgss.push_back(tg);
			E:;
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		init();
		pre();
		for(int i=0;i<=(1<<(n-1));i++){
			for(int j=0;j<n;j++){
				if(i&(1<<j))continue;
				for(int k=j+1;k<n;k++){
					if(g[j][k]==-1)continue;
					// poly p=polys[g[j][k]];
					dp[i|(tgss[g[j][k]])]=min(dp[i|(tgss[g[j][k]])],dp[i]+1);
				}
				dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+1);
			}
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}
}
