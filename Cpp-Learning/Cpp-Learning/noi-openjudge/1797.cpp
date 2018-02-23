#include<cstdio>
#include<algorithm>
#include<vector>
namespace pnoi1797{
using namespace std;
const double one=1.0;
struct mt{
	int ni,vi;
	double avg;
};
bool operator< (mt m1,mt m2){
	return m1.avg>m2.avg;
}
vector<mt> mts;
int n,k,maxw;
int main(){
	scanf("%d",&k);
	while(k--){
		scanf("%d%d",&maxw,&n);
		mts.clear();
		for(int i=0;i<n;i++){
			mt mti;
			scanf("%d%d",&mti.ni,&mti.vi);
			mti.avg=(one*(mti.vi))/(mti.ni);
			mts.push_back(mti);
		}
		sort(mts.begin(),mts.end());
		int w=0,dw;
		double v=0.0;
		for(int i=0;i<mts.size();i++){
			mt mti=mts[i];
			// cout<<mti.ni<<' '<<mti.vi<<' '<<mti.avg<<endl;
			dw=maxw-w;
			if(dw>=mti.ni){
				w+=mti.ni;
				v+=mti.vi;
			}else{
				// w=maxw;
				v+=mti.avg*dw;
				break;
			}
		}
		printf("%.2f\n",v);
	}
	return 0;
}
}
