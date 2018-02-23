#include<bits/stdc++.h>
namespace pnoi1727{
using namespace std;
const int maxn=25;
int a[maxn]={1},n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=0,ans=0,t1;
	while(t<=n){
		if(a[t]==0){
			ans+=2;
			t+=1;
		}else{
			ans+=1;
			t1=t;
			t+=a[t];
			a[t1]=0;
		}
		if(t<0)t=0;
	}
	cout<<ans;
	return 0;
}
}
