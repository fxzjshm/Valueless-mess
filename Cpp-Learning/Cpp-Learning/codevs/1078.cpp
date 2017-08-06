#include<bits/stdc++.h>
using namespace std;
namespace p1078{
struct rd{
	int s,t,len;
};
vector<rd> rs;
int n,ans,f[105];
bool operator<(rd r1,rd r2){
	return r1.len<r2.len;
}
int g(int x){
	if(f[x]==x)return x;
	f[x]=g(f[x]);
	return f[x];
}
void u(int a,int b){
	int fa=g(a),fb=g(b);
	if(fa!=fb)f[fa]=fb;
}
int main(){
	cin>>n;
	int d;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>d;
			if(i!=j){
				rd r;
				r.s=i;
				r.t=j;
				r.len=d;
				rs.push_back(r);
			}
		}
	}
	sort(rs.begin(),rs.end());
	for(int i=0;i<rs.size();i++){
		if(g(rs[i].s)!=g(rs[i].t)){
			ans+=rs[i].len;
			u(rs[i].s,rs[i].t);
		}
	}
	cout<<ans;
	return 0;
}
}
