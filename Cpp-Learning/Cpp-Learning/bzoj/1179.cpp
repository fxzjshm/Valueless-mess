// 14944/15000 ms. be careful
#include<bits/stdc++.h>
using namespace std;
namespace pb1179{
const int MAXN=500005;

int m,n,ans=0,flag=0,p;

struct rd{
	int to,w,next;
};

namespace p1{
    int s;
	vector<rd> rds;
	int head[MAXN],c[MAXN],isbar[MAXN];
}

struct sc{
	vector<int> pts;
	int w;
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
			s.w=0;
			do{
				y=stk[stk.size()-1];
				stk.pop_back();
				inq[y]=0;
				belong[y]=scid;
				s.w+=c[y];
				s.pts.push_back(y);
			}while(y!=x);
			scs.push_back(s);
		}
	}
}

namespace p2{
	vector<rd> rds;
	int head[MAXN];
}

inline void init(){
	rd r0;
	r0.next=0;
	r0.to=0;
	r0.w=0;
	p1::rds.push_back(r0);
	p2::rds.push_back(r0);
	sc sc0;
	sc0.w=0;
	scs.push_back(sc0);
}

inline void readin(){
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		rd r;
		r.to=b;
		r.next=p1::head[a];
		p1::rds.push_back(r);
		p1::head[a]=p1::rds.size()-1;
	}
	for(int i=1;i<=n;i++){
		cin>>p1::c[i];
	}
	cin>>p1::s>>p;
	int t;
	for(int i=1;i<=p;i++){
		cin>>t;
		p1::isbar[t]=1;
	}
}

inline void work(){
	for(int i=1;i<=n;i++){
		if(!tarjan::vis[i]){
			tarjan::tarjan(i);
		}
	}
}

inline void rebuild(){
	for(int i=1;i<=n;i++){
		for(int p=p1::head[i];p;p=p1::rds[p].next){
			if(belong[i]!=belong[p1::rds[p].to]){
				rd r;
				r.to=belong[p1::rds[p].to];
				r.w=scs[belong[i]].w+scs[belong[p1::rds[p].to]].w;
				r.next=p2::head[belong[i]];
				p2::head[belong[i]]=p2::rds.size();
				p2::rds.push_back(r);
			}
		}
	}
}

namespace spfa{
	using namespace p2;
	queue<int> q;
	int inq[MAXN];
	long long d[MAXN];
	void push(int x){
		if(!inq[x]){
			q.push(x);
			inq[x]=1;
		}
	}
	int pop(){
		int x=q.front();
		q.pop();
		inq[x]=0;
		return x;
	}
	inline void spfa(){
		memset(inq,0,sizeof(inq));
		memset(d,0,sizeof(d));
		push(belong[p1::s]);
		while(!q.empty()){
			int t=pop();
			for(int p=head[t];p;p=rds[p].next){
				if(d[rds[p].to]<d[t]+rds[p].w){
					d[rds[p].to]=d[t]+rds[p].w;
					push(rds[p].to);
				}
			}
		}
	}
}

inline void cnt(){
	long long maxn=0,temp=0;
	for(int i=1;i<=n;i++){
		if(p1::isbar[i]){
            temp=(spfa::d[belong[i]]+scs[belong[p1::s]].w+scs[belong[i]].w)/2;
			maxn=max(temp,maxn);
		}
	}
	cout<<maxn<<endl;
}

int main(){
	init();
	readin();
	work();
	rebuild();
	spfa::spfa();
	cnt();
	return 0;
}
}
