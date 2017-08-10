#include<bits/stdc++.h>
using namespace std;
namespace p2822{
const int MAXN=10005;

int m,n,ans=0,flag=0;

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

namespace p2{
	vector<rd> rds;
	int head[MAXN];
}

inline void init(){
	rd r0;
	p1::rds.push_back(r0);
	p2::rds.push_back(r0);
	sc sc0;
	scs.push_back(sc0);
}

inline void readin(){
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

inline void rebuild(){
	for(int i=1;i<=n;i++){
		for(int p=p1::head[i];p;p=p1::rds[p].next){
			if(belong[i]!=belong[p1::rds[p].to]){
				rd r;
				r.to=belong[p1::rds[p].to];
				r.next=p2::head[belong[i]];
				p2::head[belong[i]]=p2::rds.size();
				p2::rds.push_back(r);
			}
		}
	}
}

inline void count(){
	for(int i=1;i<scs.size();i++){
		if(p2::head[i]==0){
			if(flag){
				ans=0;
			}else{
				ans=i;
				flag=1;
			}
		}
	}
}

inline void print(){
	int cnt=0;
	for(int i=0;i<scs.size();i++){
		if(scs[i].pts.size()>1){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	if(ans&&scs[ans].pts.size()>1){
		sort(scs[ans].pts.begin(),scs[ans].pts.end());
		for(int i=0;i<scs[ans].pts.size();i++){
			cout<<scs[ans].pts[i]<<' ';
		}
	}else{
		cout<<-1;
	}
}

int main(){
	cin>>n>>m;
	init();
	readin();
	work();
	rebuild();
	count();
	print();
	return 0;
}
}
