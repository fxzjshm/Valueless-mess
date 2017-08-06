#include<bits/stdc++.h>
using namespace std;
namespace pv1404{
struct rd{
	int next,to;
	long long w;
};
vector<rd> rds;
int n,s,e,head[90005];
void ist(int si,int ei,long long ci){
	// cout<<"Insert:"<<si<<' '<<ei<<' '<<ci<<endl;
	rd r;
	r.w=ci;
	r.to=ei;
	r.next=head[si];
	head[si]=rds.size();
	rds.push_back(r);
}
namespace spfa{
	queue<int> q;
	int inq[90005];
	long long d[90005];
	void put(int x){
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
	void spfa(){
		memset(d,0x3f,sizeof(d));
		d[s]=0L;
		put(s); // 1 -> s
		while(!q.empty()){
			int t=pop();
			for(int p=head[t];p;p=rds[p].next){
				// cout<<"SPFA:"<<t<<"->"<<rds[p].to<<":"<<rds[p].w<<endl;
				if(rds[p].w+d[t]<d[rds[p].to]){
					d[rds[p].to]=rds[p].w+d[t];
					put(rds[p].to);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&s,&e);
	rd r0;
	rds.push_back(r0);
	int si,ei;
	long long ci=0;
	for(int i=1;i<=n;i++){
		ci=0;
		scanf("%d%d%lld",&si,&ei,&ci);
		if(ei>=s&&si<=e){
			ist(max(s,si),min(ei,e)+1,ci);
			ist(min(ei,e)+1,max(si,s),ci);
		}
	}
	for(int i=s;i<=e+1;i++){
		ist(i+1,i,0L);
	}
	// cout<<"Roads:"<<endl;
	/*for(int i=s;i<=e;i++){
		int p=head[i];
		cout<<"Head of "<<i<<":"<<p<<endl;
		for(;p;p=rds[p].next){
			cout<<i<<"->"<<rds[p].to<<":"<<rds[p].w<<" "<<rds[p].next<<endl;
		}
	}*/
	spfa::spfa();
    /*cout<<"result:"<<endl;
	for(int i=s;i<=e;i++)cout<<spfa::d[i]<<' ';
	cout<<endl;*/
	if(spfa::d[e+1]<0x3f3f3f3fL)cout<<spfa::d[e+1];
	else cout<<-1;
	return 0;
}
}
