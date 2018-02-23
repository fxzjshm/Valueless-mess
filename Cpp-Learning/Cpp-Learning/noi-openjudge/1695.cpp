#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
namespace pnoi1695{
using namespace std;

struct pt{
	double x,y;
};
vector <pt> ps;
int n;
double md=0,d,dx,dy;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		pt p;
		cin>>p.x>>p.y;
		ps.push_back(p);
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			dx=ps[i].x-ps[j].x;
			dy=ps[i].y-ps[j].y;
			md=max(md,sqrt(dx*dx+dy*dy));
		}
	}
	printf("%.4f\n",md);
	return 0;
}
}
