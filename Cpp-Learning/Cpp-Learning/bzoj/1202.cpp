// buggy
#include<bits/stdc++.h>
using namespace std;
namespace pb1202{
int w,n,m,f[101],d[101],flag;
int g(int x){
	if(f[x]==x)return x;
	int nf=g(f[x]);
	d[x]+=d[f[x]];
	f[x]=nf;
	return f[x];
}
void work(int s,int t,int x){
	int fa=g(s),fb=g(t);
	if(fa!=fb){
		f[fa]=fb;
		d[fa]=d[t]-d[s]-x;
		/*
		x=abs[b]-abs[a]
		v'[fa]=abs[fa]-abs[fb]
		      =(abs[a]-v[a])-(abs[b]-v'[b])
		      =-x-v[a]+v'[b]
		      =v[b]-v[a]-x
		*/
	}else if(d[t]-d[s]!=x){
			flag=0;
	}
}
int main(){
	for(cin>>w;w>0;w--){
		cin>>n>>m;
		memset(d,0,sizeof(d));
		flag=1;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		int s,t,v;
		for(int i=1;i<=m;i++){
			cin>>s>>t>>v;
			work(s-1,t,v);
			/*cout<<"  ";
			for(int i=1;i<=n;i++)cout<<i<<' ';
			cout<<endl;
			cout<<"f ";
			for(int i=1;i<=n;i++)cout<<f[i]<<' ';
			cout<<endl;
			cout<<"d ";
			for(int i=1;i<=n;i++)cout<<d[i]<<' ';
			cout<<endl;*/
		}
		if(flag)cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
	return 0;
}
}
