#include<iostream>
#include<string>
namespace pp2955{
const int maxn=105;
std::string s;
int cch[maxn][maxn],a[maxn][maxn];
int ans,n;
int chk(int i,int j){
	if(a[i][j])return cch[i][j];
	if(i>j){
		cch[i][j]=0;
	}else{
		if((s[i]=='('&&s[j]==')')
		 ||(s[i]=='['&&s[j]==']')){
		 	cch[i][j]=chk(i+1,j-1)+2;
		 }
		for(int k=i;k<j;k++){
		 	cch[i][j]=std::max(cch[i][j],chk(i,k)+chk(k+1,j));
		}

	}
	if(cch[i][j]==1)ans=std::max(ans,j-i+1);
	// std::cout<<"cch["<<i<<"]["<<j<<"]="<<cch[i][j]<<std::endl;
	a[i][j]=1;
	return cch[i][j];
}
int main(){
	while(1){
		std::cin>>s;
		ans=0;
		if(s=="end")break;
		n=s.size();
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				cch[i][j]=0;
				a[i][j]=0;
			}
		}
		chk(0,n-1);
		std::cout<<cch[0][n-1]<<std::endl;
		/*for(int i=0;i<=n;i++){
			std::cout<<"i="<<i<<' ';
			for(int j=0;j<=n;j++){
				std::cout<<cch[i][j]<<' ';
			}
			std::cout<<std::endl;
		}*/
	}
	return 0;
}
}
