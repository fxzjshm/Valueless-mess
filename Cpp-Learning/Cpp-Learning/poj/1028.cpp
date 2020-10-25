#include<iostream>
#include<cstring>
using namespace std;
namespace pp1028{
const int MAXN=105;
string urls[MAXN],tmps,url,ignored="Ignored";
int p=1,l=1;

int main(){
	ios::sync_with_stdio(false);
	urls[1]="http://www.acm.org/";
	while(1){
		cin>>tmps;
		if(tmps=="VISIT"){
			cin>>url;
			p++;
			l=p;
			urls[p]=url;
			cout<<url<<endl;
		}else if(tmps=="BACK"){
			if(p>1){
				p--;
				cout<<urls[p]<<endl;
			}else{
				cout<<ignored<<endl;
			}
		}else if(tmps=="FORWARD"){
			if(p<l){
				p++;
				cout<<urls[p]<<endl;
			}else{
				cout<<ignored<<endl;
			}
		}else if(tmps=="QUIT"){
			break;
		}
	}
	return 0;
}
}
