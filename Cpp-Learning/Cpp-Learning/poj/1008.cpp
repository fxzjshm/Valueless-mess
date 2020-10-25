#include<iostream>
#include<string>
using namespace std;
namespace pp1008{
inline int getMonth(string s){
	if(s=="pop"){
		return 0;
	}
	if(s=="no"){
		return 1;
	}
	if(s=="zip"){
		return 2;
	}
	if(s=="zotz"){
		return 3;
	}
	if(s=="tzec"){
		return 4;
	}
	if(s=="xul"){
		return 5;
	}
	if(s=="yoxkin"){
		return 6;
	}
	if(s=="mol"){
		return 7;
	}
	if(s=="chen"){
		return 8;
	}
	if(s=="yax"){
		return 9;
	}
	if(s=="zac"){
		return 10;
	}
	if(s=="ceh"){
		return 11;
	}
	if(s=="mac"){
		return 12;
	}
	if(s=="kankin"){
		return 13;
	}
	if(s=="muan"){
		return 14;
	}
	if(s=="pax"){
		return 15;
	}
	if(s=="koyab"){
		return 16;
	}
	if(s=="cumhu"){
		return 17;
	}
	if(s=="uayet"){
		return 18;
	}

}

string name[20]={
	"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

int main(){
	ios::sync_with_stdio(false);
	int N,d,m,y,x;
	string s;
	char c;
	cin>>N;
	cout<<N<<endl;
	while(N--){
		cin>>d>>c>>s>>y;
		m=getMonth(s);
		x=y*365+m*20+d;
		cout<<(x%13)+1<<' '<<name[x%20]<<' '<<(x/260)<<endl;
	}
	return 0;
}
}
