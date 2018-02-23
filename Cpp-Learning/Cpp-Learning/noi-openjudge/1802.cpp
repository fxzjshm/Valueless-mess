#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
namespace pnoi1802{
using namespace std;
string s;
int c['Z'-'A'+1],maxn=0;
int main(){
	// freopen("1205.out","w",stdout);
	memset(c,0,sizeof(c));
	for(int t=1;t<=4;t++){
		getline(cin,s);
		for(int j=0;j<s.size();j++){
			if('A'<=s[j]&&s[j]<='Z'){
				c[s[j]-'A']++;
				maxn=max(maxn,c[s[j]-'A']);
			}
		}
	}
	for(int l=maxn;l>0;l--){
		// cout<<l<<endl;
		int last=-1;
		for(int i=0;i<='Z'-'A';i++){
			if(c[i]>=l){
				for(int j=1;j<=((last<0)?(2*i):(2*(i-last-1)+1));j++)printf(" ");
				last=i;
				printf("*");
			}
		}
		cout<<endl;
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}
}
