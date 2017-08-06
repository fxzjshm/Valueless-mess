// Wrong Answer (9%)
#include<bits/stdc++.h>
using namespace std;
namespace p218_5_5_242_9018__1301{
struct rd{
	int si,ti;
	double d;
};
vector<rd> rds[1005];
struct pt{
	int x,y,z;
};
vector<pt> pts;
int n,r,d,v;
namespace spfa{
	double d[1005];
	int inq[1005];
	queue<int> q;
	void put(int x){
		q.push(x);
		inq[x]=1;
	}
	int pop(){
		int x=q.front();
		q.pop();
		inq[x]=0;
		return x;
	}
	void spfa(){
		for(int i=0;i<=n;i++){
			d[i]=1e9;
		}
		d[1]=0;
		put(1);
		while(!q.empty()){
			int x=pop();
			// cout<<x<<endl;
			for(int i=0;i<rds[x].size();i++){
				if((d[rds[x][i].ti]>d[x]+rds[x][i].d)){
					d[rds[x][i].ti]=d[x]+rds[x][i].d;
					put(rds[x][i].ti);
				}
			}
		}
	}
}
int main(){
	double ds,dh;
	cin>>n>>r>>d>>v;
	pts.push_back(pt());
	for(int i=1;i<=n;i++){
		pt p;
		cin>>p.x>>p.y>>p.z;
		for(int j=1;j<pts.size();j++){
			ds=sqrt((pts[j].x-p.x)*(pts[j].x-p.x)
			       +(pts[j].y-p.y)*(pts[j].y-p.y));
			if((ds>r))continue;
			dh=double(abs(pts[j].z-p.z));
			if((dh>d))continue;
			rd r1,r2;
			r1.si=r2.ti=pts.size();
			r1.ti=r2.si=j;
			r1.d=r2.d=sqrt(ds*ds+dh*dh);
			rds[r1.si].push_back(r1);
			rds[r2.si].push_back(r2);
		}
		pts.push_back(p);
	}
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<rds[i].size();j++){
			printf("s=%d,t=%d,d=%lf\n",rds[i][j].si,rds[i][j].ti,rds[i][j].d);
		}
	}*/
	spfa::spfa();
	/*for(int i=0;i<=n;i++){
		cout<<i<<' '<<spfa::d[i]<<endl;
	}*/
	double t=spfa::d[n]/v;
	if(spfa::d[n]<10e9)printf("%.3lf",t);
	else printf("No Solution");
	return 0;
}
}
