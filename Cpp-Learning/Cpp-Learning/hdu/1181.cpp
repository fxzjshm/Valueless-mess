// not completed!
#include<cstdio>
#include<cstring>
#include<memory.h>
namespace ph1181{
struct{
	char l,r;
}word[10000005];
char s[100005];
int n=0;
int main(){
	while(gets(s)){
		memset(word,0,sizeof(word));
		while(s[0]!='0'){
			word[n].l=s[0];
			word[n].r=s[strlen(s)];
			gets(s);
		}
	}
	return 0;
}
}
