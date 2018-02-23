#include<iostream>
namespace pnoi1707{
using namespace std;
int n,m,t,s;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>m;
		s=60;
		for (int j=1;j<=m;j++){
			cin>>t;
			s-=max(0,min(3,s-t));
		}
		cout<<s<<endl;
	}
	return 0;
}
}
