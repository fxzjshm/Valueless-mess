#include <bits/stdc++.h>
using namespace std;
namespace pnoi2950{
const int maxn=60005,maxl=246/*(int)(sqrt(maxn))+1*/;
int n,ns[maxn];
vector<int> ps;
int main(){
	for(long long i=2;i<maxn;i++){
		if(ns[i])continue;
		for(long long j=i*i;j<maxn;j+=i){
			ns[j]=1;
		}
	}
	for(int i=2;i<maxn;i++){
		if(!ns[i])ps.push_back(i);
	}
	// for(int i=0;i<ps.size();i++)cout<<ps[i]<<',';
	int l=ps.size();
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<l;i++){
        	int t=n,c=0;
        	while(t){
        		t/=ps[i];
        		c+=t;
        	}
        	if(c){
        		if(i)printf("*");
        		printf("%d",ps[i]);
        		if(c>1)printf("^%d",c);
        	}

        }
        printf("\n");
    }

    return 0;
}
}
