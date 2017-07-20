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

namespace ch010604{
int main(){
	int n;
	cin>>n;
	int ns[n];
	for(int i=0;i<n;i++)cin>>ns[i];
	for(int i=n;i>0;i--)cout<<ns[i-1]<<' ';
	return 0;
}
}

namespace ch010605{
int n,t,n1,n2,n3,n4;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(0<=t&&t<=18){
            n1++;
        }else if(19<=t&&t<=35){
            n2++;
        }else if(36<=t&&t<=60){
            n3++;
        }else{
            n4++;
        }
    }
    int s=n1+n2+n3+n4;
    printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%",100.0*n1/s,100.0*n2/s,100.0*n3/s,100.0*n4/s);

    return 0;
}
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

namespace pnoi010607{
int ns[3005],n,d[3005];
bool b=true;
inline int abs(int a){
	return (a<0)?(-a):a;
}
int main(){
	cin>>n;
	cin>>ns[0];
	int dt;
	for(int i=1;i<n;i++){
		cin>>ns[i];
		dt=abs(ns[i]-ns[i-1]);
		if(dt==0||dt>n-1||d[dt]!=0){
			b=false;
			break;
		}else{
			d[dt]++;
		}
	}
	for(int i=1;i<n;i++){
		if(!d[i]){
			b=false;
			break;
		}
	}
	if(b)cout<<"Jolly";
	else cout<<"Not jolly";
	return 0;
}
}

int ch010608g(int a,int b){
	if(a==b)return 0;
	if((a==0&&b==2)||(a==2&&b==5)||(a==5&&b==0))return 1;
	return -1;
}
int ch010608(){
	int n,na,nb,a=0,b=0;
	cin>>n>>na>>nb;
	int as[na],bs[nb];
	for(int i=0;i<na;i++)
		cin>>as[i];
	for(int i=0;i<nb;i++)
		cin>>bs[i];
	for(int i=0;i<n;i++){
		int t=ch010608g(as[i%na],bs[i%nb]);
		if(t<0)b++;
		if(t>0)a++;
	}
	if(a>b)cout<<"A";
	if(a<b)cout<<"B";
	if(a==b)cout<<"draw";
	return 0;
}

namespace pnoi010608{
int a[101],b[101],n,na,nb,aa,ab;
int main(){
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++){
		cin>>a[i];
	}
	for(int i=0;i<nb;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		int ai=a[i%na],bi=b[i%nb];
		if(ai==bi)continue;
		if((ai==0&&bi==2)||(ai==2&&bi==5)||(ai==5&&bi==0)){
			aa++;
		}else{
			ab++;
		}
	}
	if(aa>ab){
		cout<<'A';
	}else if(aa<ab){
		cout<<'B';
	}else{
		cout<<"draw";
	}
	return 0;
}
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
