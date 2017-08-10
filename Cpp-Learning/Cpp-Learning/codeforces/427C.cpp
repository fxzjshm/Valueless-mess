#include<bits/stdc++.h>
using namespace std;
namespace p427C{
const int MAXN=100005;

int m,n,ans=0,flag=0,c[MAXN];
unsigned long long tn=1,tc=0;

struct rd{
	int to,next;
};

namespace p1{
	vector<rd> rds;
	int head[MAXN];
}

struct sc{
	vector<int> pts;
};
vector<sc> scs;
int belong[MAXN];

namespace tarjan{
	using namespace p1;
	vector<int> stk;
	int dfn[MAXN],low[MAXN],cnt=0,vis[MAXN],inq[MAXN];
	void tarjan(int x){
		vis[x]=inq[x]=1;
		cnt++;
		dfn[x]=low[x]=cnt;
		stk.push_back(x);
		for(int p=head[x];p;p=rds[p].next){
			if(!vis[rds[p].to]){
				tarjan(rds[p].to);
				low[x]=min(low[x],low[rds[p].to]);
			}else if(inq[rds[p].to]){
				low[x]=min(low[x],dfn[rds[p].to]);
			}
		}
		if(low[x]==dfn[x]){
			int y=-1,scid=scs.size();
			sc s;
			do{
				y=stk[stk.size()-1];
				stk.pop_back();
				inq[y]=0;
				belong[y]=scid;
				s.pts.push_back(y);
			}while(y!=x);
			scs.push_back(s);
		}
	}
}

inline void init(){
	rd r0;
	p1::rds.push_back(r0);
	sc sc0;
	scs.push_back(sc0);
}

inline void readin(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cin>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		rd r;
		r.to=b;
		r.next=p1::head[a];
		p1::rds.push_back(r);
		p1::head[a]=p1::rds.size()-1;
	}
}

inline void work(){
	for(int i=1;i<=n;i++){
		if(!tarjan::vis[i]){
			tarjan::tarjan(i);
		}
	}
}

inline void count(){
	using namespace p1;
	for(int i=1;i<scs.size();i++){
		unsigned long long minc=0x7FFFFFFF,minn=0;
		for(int j=0;j<scs[i].pts.size();j++){
			if(c[scs[i].pts[j]]<minc){
				minc=c[scs[i].pts[j]];
				minn=1;
			}else if(c[scs[i].pts[j]]==minc)minn++;
		}
		tc+=minc;
		tn*=minn;
        tn%=1000000007;
	}
}

inline void print(){
	cout<<tc<<' '<<(tn%1000000007)<<endl;
}

int main(){
	init();
	readin();
	work();
	count();
	print();
	return 0;
}
}
