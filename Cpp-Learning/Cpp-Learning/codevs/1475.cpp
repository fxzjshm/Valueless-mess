#include<bits/stdc++.h>
using namespace std;
namespace p1475{
inline int g(char c){
	return ('0'<=c&&c<='9')?(c-'0'):(c-'A'+10);
}
inline char u(char c){
	return ('a'<=c&&c<='z')?(c-'a'+'A'):c;
}
int main(){
	string s;
	int t,ans=0;
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		ans*=t;
		s[i]=u(s[i]);
		ans+=g(s[i]);
	}
	cout<<ans;
	return 0;
}
}
