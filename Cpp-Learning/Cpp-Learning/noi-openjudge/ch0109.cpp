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

namespace ch010906{
string s;
map<char,int> ns;
int mi=0x7FFFFFFF,ma=0;
inline void cp(int x){
    if(x<2)goto FA;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)goto FA;
    }
    cout<<"Lucky Word"<<endl<<x;
    return;
    FA:cout<<"No Answer"<<endl<<0;
}
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        ns[s[i]]++;
    }
    for(char i='a';i<='z';i++){
        if(ns.count(i)){
            mi=min(mi,ns[i]);
            ma=max(ma,ns[i]);
        }
    }
    cp(ma-mi);
    return 0;
}
}

namespace ch010907{
int n,t,s=0,m;
map<int,int> ns;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        ns[t]++;
        s+=t;
        m=max(m,t);
    }
    cout<<s-ns[m]*m;
    return 0;
}
}

int ch010908(){
    int n;
    double t,a;
    cin>>n;
    double ns[n];
    for(int i=0;i<n;i++){
        cin>>a;
        ns[i]=a;
        t+=a;
    }
    sort(ns,ns+n);
    t-=ns[0]+ns[n-1];
    double avg=t/(n-2);
    printf("%.2f %.2f",avg,max(abs(ns[n-2]-avg),abs(avg-ns[1])));
    return 0;
}

namespace ch010909{
map<int,int> ns;
int ma=0,n,t;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        ma=max(ma,t);
        ns[t]++;
    }
    for(int i=0;i<=ma;i++){
        cout<<ns[i]<<endl;
    }
    return 0;
}
}

namespace ch010912{
int n,ml=-1,last,t,l=1;
int main(){
    cin>>n;
    cin>>last;
    for(int i=1;i<n;i++){
        cin>>t;
        if(t==last){
            l++;
        }else{
            ml=max(l,ml);
            last=t;
            l=1;
        }
    }
    ml=max(l,ml);
    cout<<ml;
    return 0;
}
}

namespace ch010913{
int n,t;
map<int,int> ns;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(!ns[t])cout<<t<<' ';
        ns[t]++;
    }
    return 0;
}
}

namespace ch010914{
struct carpet{
	int x1,y1,x2,y2;
}cs[10005];
int n;
int main(){
	cin>>n;
	int lx,ly;
	for(int i=1;i<=n;i++){
		cin>>cs[i].x1>>cs[i].y1;
		cin>>lx>>ly;
		cs[i].x2=cs[i].x1+lx;
		cs[i].y2=cs[i].y1+ly;
	}
	int x,y;
	cin>>x>>y;
	int i;
	for(i=n;i>0;i--){
		if(cs[i].x1<=x&&x<=cs[i].x2
		 &&cs[i].y1<=y&&y<=cs[i].y2){
			cout<<i;
			break;
		 }
	}
	if(i==0)cout<<-1;
	return 0;
}
}
