#include <bits/stdc++.h>
using namespace std;
int ch010901(){
	int l,m;
	cin>>l;
	int ns[l];
	for(int i=0;i<l;i++)
		cin>>ns[i];
	cin>>m;
	for(int i=0;i<l;i++)
		if(m==ns[i]){
			cout<<i+1;
			return 0;
		}
	cout<<-1;
	return 0;
}

int ch010902(){
	int n;
	cin>>n;
	int num=-1,t;
	string name,r;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t>num){
			num=t;
			cin>>name;
		}else
			cin>>r;
	}
	cout<<name;
	return 0;
}

int ch010904(){
	int n;
	char p,q;
	cin>>n;
	string highester,name;
	int final,clazz,isWorker,isWest,passage,money=0,highest=0,total=0;
	for(int i=0;i<n;i++){
		money=0;
		cin>>name>>final>>clazz>>p>>q>>passage;
		isWorker=(p=='Y')?1:0;
		isWest=(q=='Y')?1:0;
		if(final>80&&passage>0)money+=8000;
		if(final>85&&clazz>80)money+=4000;
		if(final>90)money+=2000;
		if(final>85&&isWest>0)money+=1000;
		if(clazz>80&&isWorker>0)money+=850;
		if(money>highest){highest=money;highester=name;}
		total+=money;
	}
	cout<<highester<<endl<<highest<<endl<<total;
	return 0;
}

int ch010905(){
	int n,t,min1,max1;
	cin>>n;
	cin>>t;
	min1=t;
	max1=t;
	for(int i=0;i<n-1;i++){
		cin>>t;
		min1=min(t,min1);
		max1=max(t,max1);
	}
	cout<<max1-min1;
	return 0;
}
