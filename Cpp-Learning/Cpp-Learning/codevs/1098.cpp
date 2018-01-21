#include<iostream>
using namespace std;
namespace p1098{
const int maxn=101;
int n,ns[maxn],m=0,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ns[i];
		m+=ns[i];
	}
	m/=n;
	int t;
	for(int i=1;i<n;i++){
		t=ns[i]-m;
		if(t)ans+=1;
		ns[i+1]+=t;
		ns[i]-=t;
	}
	cout<<ans;
	return 0;
}
}
