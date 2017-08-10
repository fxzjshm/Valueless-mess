#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
namespace pp1523{
const int N=1005;
int x,y,n,block[N],head[N],cnt,
	dfn[N],low[N],cn=0;
bool vis[N];
struct rd{
	int to,next;
};
vector<rd> rds;
inline void _ist(int a,int b){
	rd r;
	r.to=b;
	r.next=head[a];
	head[a]=rds.size();
	rds.push_back(r);
}
inline void ist(int a,int b){
	_ist(a,b);
	_ist(b,a);
}
inline void read(){
	cin>>x;
	if(!x)exit(0);
	cin>>y;
	ist(x,y);
	n=max(max(x,y),n);
	while(1){
		cin>>x;
		if(!x)break;
		cin>>y;
		ist(x,y);
		n=max(max(x,y),n);
	}
}
inline void init(){
	cnt=n=0;
	cn++;
	rds.clear();
	memset(block,0,sizeof(block));
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	rd r0;
	rds.push_back(r0);
	read();
	for(int i=2;i<=n;i++){
		block[i]=1;
	}
}
void tarjan(int x){
	cnt++;
	dfn[x]=low[x]=cnt;
	vis[x]=1;
	for(int p=head[x];p;p=rds[p].next){
		if(!vis[rds[p].to]){
			tarjan(rds[p].to);
			low[x]=min(low[x],low[rds[p].to]);
			if(low[rds[p].to]>=dfn[x])block[x]++;
		}else low[x]=min(low[x],dfn[rds[p].to]);
	}
}
inline void print(){
	bool flag=0;
	printf("Network #%d\n",cn);
	for(int i=1;i<=n;i++){
		if(block[i]>1){
			printf("  SPF node %d leaves %d subnets\n",i,block[i]);
			flag=1;
		}
	}
	if(!flag)printf("  No SPF nodes\n");
	printf("\n");
}
int main(){
	while(1){
		init();
		tarjan(1);
		print();
	}
	return 0;
}
}
