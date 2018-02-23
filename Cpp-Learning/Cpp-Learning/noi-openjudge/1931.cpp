#include<iostream>
#include<cstdio>
#include<vector>
namespace pnoi1931{
using namespace std;
int n;
char c;
vector<int> lbs;
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='1')lbs.push_back(i);
			else{
				cout<<lbs[lbs.size()-1]<<' ';
				lbs.pop_back();
			}
		}
		cout<<endl;
	}
	return 0;
}
}
