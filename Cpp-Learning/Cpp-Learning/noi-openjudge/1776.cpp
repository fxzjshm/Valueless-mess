#include<iostream>
#include<vector>
namespace pnoi1776{
using namespace std;
vector<int> ns;
int n,t,k,maxl=0;
inline int getn(int t){
	int ret=0;
	for(int i=0;i<ns.size();i++){
		ret+=ns[i]/t;
	}
	return ret;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t;
		maxl=max(maxl,t);
		ns.push_back(t);
	}
	int l=0,r=maxl;
	while(l<r){
		int mid=(l+r+1)/2,nt=getn(mid);
		if(nt>=k)l=mid;
		else r=mid-1;
		// cout<<l<<' '<<r<<' '<<nt<<endl;
	}
	cout<<l;
	return 0;
}
}
