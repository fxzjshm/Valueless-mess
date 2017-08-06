#include<bits/stdc++.h>
using namespace std;
namespace p1474{
inline char g(int i){
	return (0<=i&&i<=9)?('0'+i):('A'+i-10);
}
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	while(n){
		s=g(n%m)+s;
		n/=m;
	}
	cout<<s;
	return 0;
}
}
