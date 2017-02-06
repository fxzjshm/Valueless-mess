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
