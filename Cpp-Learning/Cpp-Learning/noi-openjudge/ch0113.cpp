#include<bits/stdc++.h>
using namespace std;
bool ch011310isNotFactable(long long n){
    if(n<=0)return false;
    if(n==1)return false;
    if(n==2)return true;
    if(n%2==0)
            return false;
    double maxNum=sqrt(n);
    for(unsigned long i=3;i<=maxNum;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int ch011310(){
    long long a,b,n=0;
    cin>>a>>b;
    if(a>b){
        long long temp;
        temp=a;
        a=b;
        b=temp;
    }
    for(long long i=a;i<=b;i++)
        if(ch011310isNotFactable(i))n++;
    cout<<n;
    return 0;
}

bool ch011311isNotFactable(long n){
    if(n%2==0) // 2
            return false;
    double maxNum=sqrt(n);
    for(unsigned long i=3;i<=maxNum;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int ch011311(){
    unsigned int l,l2;
    cin>>l;
    if(l==1){
        cout<<"4"<<endl;
        cout<<"2 3 5 7";
        return 0;
    }
    if(l==2){
        cout<<"1"<<endl;
        cout<<"11";
        return 0;
    }
    if(l%2==0){
        cout<<"0"<<endl;
        return 0;
    }
    long nums[5173];
    int numSize=0;
    l2=(l-1)/2;
    long long num,num2,base=pow(10,l2),basel=base/10;
    int temp;
    for(int i=basel;i<base;i++){
        num=i*10;
        temp=i;
        while(temp){
            num*=10;
            num+=temp%10;
            temp/=10;
        }
        for(int j=0;j<=9;j++){
            num2=num+j*base;
            if(ch011311isNotFactable(num2)){
                nums[numSize]=num2;
                numSize++;
            }
        }
    }
    cout<<numSize<<endl;
    for(unsigned int i=0;i<numSize;i++){
        printf("%ld ",nums[i]);
        // if(i!=nums.size()-1)cout<<" ";
    }
    return 0;
}

namespace ch011320{
vector<int> ns[10005];
int n;
int main(){
	cin>>n;
	int a,k,b;
	for(int i=1;i<=n;i++){
		cin>>a>>k;
		for(int j=1;j<=k;j++){
			cin>>b;
			ns[b].push_back(a);
		}
	}
	int ind,len=0;
	for(int i=1;i<=10000;i++){
		if(ns[i].size()>len){
			ind=i;
			len=ns[i].size();
		}
	}
	sort(ns[ind].begin(),ns[ind].end());
	cout<<ind<<endl<<ns[ind][0]<<' ';
	for(int i=1;i<ns[ind].size();i++){
		if(ns[ind][i]!=ns[ind][i-1])cout<<ns[ind][i]<<' ';
	}
	return 0;
}
}

namespace ch011329{
map<char,int> ns;
string s;
int ma=0,n,t;
char mc;
int main(){
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        ns[s[i]]++;
    }
    for(char i='a';i<='z';i++){
        if(ns[i]>ma){
            ma=ns[i];
            mc=i;
        }
    }
    cout<<mc<<' '<<ma;
    return 0;
}
}

namespace ch011331{
int ml=-1,l=1;
char last,t,mc;
string s;
int main(){
    cin>>s;
    mc=last=s[0];
    for(int i=1;i<s.size();i++){
        t=s[i];
        if(t==last){
            l++;
        }else{
            if(l>ml){
                ml=l;
                mc=last;
            }
            last=t;
            l=1;
        }
    }
    if(l>ml){
        ml=l;
        mc=last;
    }
    cout<<mc<<' '<<ml;
    return 0;
}
}

namespace ch011342{
vector<int> ns['Z'+1];
int n;
int main(){
	cin>>n;
	int ord;
	string s;
	for(int i=1;i<=n;i++){
		cin>>ord>>s;
		for(int i=0;i<s.length();i++){
			ns[s[i]].push_back(ord);
		}
	}
	int ind='A';
	for(int i='B';i<='Z';i++){
		if(ns[i].size()>ns[ind].size()){
			ind=i;
		}
	}
	cout<<char(ind)<<endl<<ns[ind].size()<<endl;
	for(int i=0;i<ns[ind].size();i++){
		cout<<ns[ind][i]<<endl;
	}
	return 0;
}
}
