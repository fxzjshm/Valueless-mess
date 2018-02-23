#include<cstdio>
#include<cstring>
#include<memory.h>
namespace ph1181{
struct{
	char l,r;
	int used;
}word[100005];
char s[100005];
int n=0;
bool dfs(char s,char t){
    if(s==t)return true;
    for(int i=0;i<n;i++){
        if(!word[i].used&&word[i].l==s){
            word[i].used=1;
            if(dfs(word[i].r,t))return true;
            word[i].used=0;
        }
    }
    return false;
}
int main(){
	while(fgets(s,sizeof(s),stdin)){
		memset(word,0,sizeof(word));
		while(s[0]!='0'){
			word[n].l=s[0];
			word[n].r=s[strlen(s)-1];
			n++;
			fgets(s,sizeof(s),stdin);
		}
		if(dfs('b','m'))printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}
}
