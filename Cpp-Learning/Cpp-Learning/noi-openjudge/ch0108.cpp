#include <bits/stdc++.h>
using namespace std;
int ch010802(){
	int N,a,b;
	cin>>N>>a>>b;
	for(int i=1;i<=N;i++)
		cout<<"("<<a<<","<<i<<")"<<" ";
	cout<<endl;
	for(int i=1;i<=N;i++)
		cout<<"("<<i<<","<<b<<")"<<" ";
	cout<<endl;
	int x,y;
	for(int i=N;i>=-max(a,b);i--){
		x=a-i;
		y=b-i;
		if(1<=x&&x<=N&&1<=y&&y<=N)cout<<"("<<x<<","<<y<<")"<<" ";
	}
	cout<<endl;
	for(int i=-max(a,b);i<=N;i++){
		x=a-i;
		y=b+i;
		if(1<=x&&x<=N&&1<=y&&y<=N)cout<<"("<<x<<","<<y<<")"<<" ";
	}
	cout<<endl;
	return 0;
}

int ch010803(){
	int m,n,a=0;
	cin>>m>>n;
	int ns[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ns[i][j];
	for(int j=1;j<n-1;j++)
		a+=ns[0][j]+(1!=m?ns[m-1][j]:0);
	for(int i=1;i<m-1;i++)
		a+=ns[i][0]+(1!=n?ns[i][n-1]:0);
	a+=ns[0][0]+(1!=n?ns[0][n-1]:0)+(1!=m?ns[m-1][0]:0)+(1!=m&&1!=n?ns[m-1][n-1]:0);
	cout<<a;
	return 0;
}

int ch010806(){
	int m,n,nt=0;
	cin>>m>>n;
	int ns[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ns[i][j];
	int t;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>t;
			if(t==ns[i][j])nt++;
		}
	}
	printf("%.2f",100.0*nt/(m*n));
	return 0;
}

int ch010808(){
	int m,n,a=0;
	cin>>m>>n;
	int ns[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ns[i][j];
	int t;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cin>>t;
			ns[i][j]+=t;
		}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<ns[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

int ch010809(){
	int n,f=1,t=1;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])t++;
	cout<<t<<endl;
	cout<<a[0]<<' ';
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])cout<<a[i]<<' ';
	return 0;
}

int ch010810(){
	int m,n;
	cin>>m>>n;
	int ns[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ns[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<ns[j][i]<<" ";
	cout<<endl;
	}
	return 0;
}
