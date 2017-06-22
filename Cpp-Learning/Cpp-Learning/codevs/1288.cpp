#include<cstdio>
#include<cmath>
#include<iostream>
#include<memory.h>
using namespace std;
namespace p1288{
int deplim,a,b,ans[10000],ns[10000],f=0;
bool check(){
	if(ns[deplim]!=0&&ans[deplim]>ns[deplim]){
		double t;
		for(int i=1;i<=deplim;i++){
			t+=1.0/ns[i];
		}
		if(-0.0000001<t-double(a)/b&&t-double(a)/b<0.0000001){
			memcpy(ans,ns,sizeof(ns));
			f=1;
			return true;
		}
	}return false;
}
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
void dfs(int depth,int a,int b){
	if(check()||depth>deplim)return;
	int t=gcd(a,b);
	a/=t;b/=t;
	int i=1;
	for(;1.0/i>double(a)/b;i++);
	for(;2.0/i>=double(a)/b;i++){
		ns[depth]=i;
		dfs(depth+1,a*i-b,b*i);
	}
}
void print(){
	for(int i=1;i<deplim-1;i++){
		cout<<ans[i]<<' ';
	}
	cout<<ans[deplim-1];
}
int main(){
	memset(ans,0x7f,sizeof(ans));
	cin>>a>>b;
	for(;f==0;deplim++){
		// cout<<deplim<<endl;
		memset(ns,0,sizeof(ns));
		dfs(1,a,b);
	}
	print();
	return 0;
}
}
