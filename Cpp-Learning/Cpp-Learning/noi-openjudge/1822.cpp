#include<algorithm>
#include<iostream>
#include<string>
namespace pnoi1822{
using namespace std;
const int maxn=35;
int c1[maxn],c2[maxn];
string s1,s2;
int main(){
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++){
		c1[s1[i]-'A']++;
	}
	sort(c1,c1+maxn-2);
	for(int i=0;i<s2.size();i++){
		c2[s2[i]-'A']++;
	}
	sort(c2,c2+maxn-2);
	for(int i=1;i<maxn;i++){
		if(c1[i]!=c2[i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
}
