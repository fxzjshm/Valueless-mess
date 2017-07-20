#include<iostream>
using namespace std;
namespace pnoi2722{
int n,ns[105],exist[20005],ans=0,used[20005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ns[i];
		exist[ns[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(exist[i+j]&&(!used[i+j])){
				ans+=exist[i+j];
				used[i+j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
}
