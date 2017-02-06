#include <bits/stdc++.h>
using namespace std;

int ch010601(){
    int l,t,n,a=0;
    cin>>l;
    long long ns[l];
    for(int i=0;i<l;i++){
        cin>>t;
        ns[i]=t;
    }
    cin>>n;
    for(int i=0;i<l;i++)
        if(ns[i]==n)a++;
    cout<<a;
    return 0;
}

int ch010602(){
    int t,n,a=0;
    long long ns[10];
    for(int i=0;i<10;i++){
        cin>>t;
        ns[i]=t;
    }
    cin>>n;
    for(int i=0;i<10;i++)
        if(ns[i]<=n+30)a++;
    cout<<a;
    return 0;
}

int ch010603(){
    double m[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
    int t;
    double a=0;
    for(int i=0;i<10;i++){
        cin>>t;
        a+=t*m[i];
    }
    printf("%.1f",a);
    return 0;
}

int ch010606(){
	int l,m,a;
	int ns[100005];
	cin>>l>>m;
	a=l+1;
	for(int i=0;i<=l;i++)
		ns[i]=0;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		ns[a]+=1;
		ns[b]-=1;
	}
	int t=0,lt=0;
	for(int i=0;i<=l;i++){
		int s,e;
		lt=t;
		t+=ns[i];
		if(t>0&&lt==0){
			s=i;
		}
		if(t==0&&lt>0){
			e=i;
			a-=e-s+1;
		}
	}
	cout<<a;
	return 0;
}

int ch010607(){
	int n,l,t;
	cin>>n;
	int ns[n];
	for(int i=0;i<n;i++)
		ns[i]=0;
	cin>>t;
	for(int i=0;i<n-1;i++){
		l=t;
		cin>>t;
		int d=abs(t-l);
		if(d>=n||ns[d]>=1){
			cout<<"Not jolly";
			return 0;
		}
		ns[d]+=1;
	}
	cout<<"Jolly";
	return 0;
}

int ch010609(){
	int n,a=0,t;
	cin>>n;
	int ns[n];
	for(int i=0;i<n;i++)
		cin>>ns[i];
	for(int i=0;i<n;i++){
		cin>>t;
		a+=ns[i]*t;
	}
	cout<<a;
	return 0;
}
