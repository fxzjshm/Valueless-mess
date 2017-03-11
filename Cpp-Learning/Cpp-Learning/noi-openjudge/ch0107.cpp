#include<bits/stdc++.h>
using namespace std;

#define l 256
int ch010701(){
	char bs[l];
	int a=0;
	for(int i=0;i<l;i++)
		bs[i]=0;
	gets(bs);
	for(int i=0;i<l;i++)
		('0'<=bs[i]&&'9'>=bs[i])?a++:0;
	cout<<a;
	return 0;
}
#undef l

int ch010702(){
    string s;
    cin>>s;
    int cs[256];
    for(int i=0;i<256;i++)cs[i]=-1;
    for(int i=0;i<s.size();i++){
        if(cs[s[i]]==-1)cs[s[i]]=i;
        else cs[s[i]]=-2;
    }
    string a="no";
    int id=s.size();
    for(int i=0;i<256;i++){
        if(cs[i]>=0&&cs[i]<id){
            a=(char)i;
            id=cs[i];
        }
    }
    cout<<a;
    return 0;
}


int ch010703(){
	double n;
	string s1,s2,temp;
	cin>>n;
	int /*len=0,*/m=0;
	/*char t;*/
	getline(cin,temp);
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s1.size();i++)
		if(s2[i]==s1[i])m++;
	cout<<(((1.0*m/s1.size())>=n)?"yes":"no");
	return 0;
}

int ch010704(){
    int n;
    cin>>n;
    string p1,p2;
    for(int i=0;i<n;i++){
        cin>>p1>>p2;
        if(p1==p2)cout<<"Tie"<<endl;
        else if((p1=="Rock"&&p2=="Scissors")||(p1=="Scissors"&&p2=="Paper")||(p1=="Paper"&&p2=="Rock"))cout<<"Player1"<<endl;
        else cout<<"Player2"<<endl;
    }
    return 0;
}

int ch010705(){
    char s[105],s1[105];
    gets(s); // ' '
    int l=strlen(s);
    strcpy(s1,s);
    for(int i=0;i<l-1;i++)s1[i]=s[i]+s[i+1];
    s1[l-1]=s[l-1]+s[0];
    cout<<s1;
    return 0;
}


int ch010707(){
	string s1;
	getline(cin,s1);
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='A')cout<<'T';
		if(s1[i]=='T')cout<<'A';
		if(s1[i]=='C')cout<<'G';
		if(s1[i]=='G')cout<<'C';
	}
	return 0;
}

int ch010708(){
	string s,a,b;
	int n;
	cin>>s>>a>>b;
	n=s.find(a,0);
	while(n!=string::npos){
		s.replace(n,1,b);
		n=s.find(a,n+1);
	}
	cout<<s;
	return 0;
}

char ch010709g(char x){
	if('a'<=x&&x<'z')return x+1;
	if(x=='z')return 'a';
	if('A'<=x&&x<'Z')return x+1;
	if(x=='Z')return 'A';
	return x;
}
int ch010709(){
	string s;
	getline(cin,s);
	string a(s);
	for(int i=0;i<s.size();i++)
		a[i]=ch010709g(s[i]);
	cout<<a;
	return 0;
}

char ch010710t(char a){
	if('A'<=a&&a<='E')return a+21;
	if('F'<=a&&a<='Z')return a-5;
	return a;
}
int ch010710(){
	char s[205];
	gets(s);
	for(int i=0;i<strlen(s);i++)cout<<ch010710t(s[i]);
	return 0;
}

char ch010712g(char x){
	if('a'<=x&&x<='w')return x+3-'a'+'A';
	if('A'<=x&&x<='W')return x+3-'A'+'a';
	if('x'<=x&&x<='z')return x-23-'a'+'A';
	if('X'<=x&&x<='Z')return x-23-'A'+'a';
	return x;
}
int ch010712(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		s[i]=ch010712g(s[i]);
	for(int i=s.size()-1;i>=0;i--)
		cout<<s[i];
	return 0;
}

char ch010713g(char x){
	if('a'<=x&&x<='z')return x-'a'+'A';
	return x;
}
int ch010713(){
	string s;
	getline(cin,s);
	string a(s);
	for(int i=0;i<s.size();i++)
		a[i]=ch010713g(s[i]);
	cout<<a;
	return 0;
}

char ch010714t(char a){
	if('A'<=a&&a<='Z')return a-'A'+'a';
	if('a'<=a&&a<='z')return a-'a'+'A';
	return a;
}
int ch010714(){
	char s[105];
	gets(s);
	for(int i=0;i<strlen(s);i++)cout<<ch010714t(s[i]);
	return 0;
}

char ch010715U2l(char x){
	if('A'<=x&&x<='Z')return x-'A'+'a';
	return x;
}
char ch010715l2U(char x){
	if('a'<=x&&x<='z')return x-'a'+'A';
	return x;
}
int ch010715(){
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		s[0]=ch010715l2U(s[0]);
		for(int j=1;j<s.size();j++)s[j]=ch010715U2l(s[j]);
		cout<<s<<endl;
	}
	return 0;
}

string ch010717p(string s){
	for(int i=0;i<s.size();i++){
		L1:if(s[i]==' '){
			s.erase(i,1);
			goto L1;
		}
		if('A'<=s[i]&&s[i]<='Z')s[i]-='A'-'a';
	}
	return s;
}
int ch010717(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(ch010717p(a)==ch010717p(b))cout<<"YES";
	else cout<<"NO";
	return 0;
}

int ch010720(){
	string s;
	cin>>s;
	int l=s.size();
	string s2=(l>1)?s.substr(l-2,2):"";
	string s3=(l>2)?s.substr(l-3,3):"";
	if(s2==string("ly")||s2==string("er")){
		cout<<s.substr(0,l-2);
		return 0;
	}
	if(s3==string("ing")){
		cout<<s.substr(0,l-3);
		return 0;
	}
	cout<<s;
	return 0;
}

int ch010723(){
	string s;
	getline(cin,s);
	while(1){
		int p=s.find("  ",0);
		if(p==string::npos)break;
		s.replace(p,2," ");
	}
	cout<<s;
	return 0;
}

int ch010724(){
	char s[1000];
	int f=0;
	while(cin>>s){
		if(!f)f=1;
		else{cout<<",";}
		cout<<strlen(s);
	}
	return 0;
}

int ch010726(){
	string t,s,s1,s2;
	int n,l,r,t1,a;
	cin>>t;
	n=t.find(',',0);
	while(n!=string::npos){
		t.replace(n,1," ");
		n=t.find(',',0);
	}
	stringstream ss;
	ss<<t;
	ss>>s>>s1>>s2;
	if((l=s.find(s1,0))==string::npos){
		cout<<-1;
		return 0;
	}
	l+=s1.size()-1;
	for(int i=s.size()-1;i>-1;i--){
		t1=s.find(s2,i);
		if(t1!=string::npos){
			r=t1;
			break;
		}
	}
	a=r-l-1;
	if(a<0)cout<<-1;
	else cout<<a;
	return 0;
}

int ch010729(){
	string s;
	cin>>s;
	/*while(1){
		int p=s.find("-",0);
		if(p==string::npos)break;
		s.erase(p,1);
	}
	cout<<s;*/
	int t=0,m=0;
	for(int i=0;i<s.size()-1;i++){
		if('0'<=s[i]&&s[i]<='9'){
			m++;
			t+=m*(s[i]-'0');
		}
	}
	t%=11;
	if(t==s[s.size()-1]-'0'||(t==10&&s[s.size()-1]=='X'))cout<<"Right";
	else{
		for(int i=0;i<s.size()-1;i++){
			cout<<s[i];
		}
		if(t==10)cout<<'X';
		else cout<<t;
	}
	return 0;
}
