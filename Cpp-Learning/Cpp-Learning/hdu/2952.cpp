#include<iostream>
#include<memory.h>
using namespace std;
namespace ph2952{
int n,a,b,ans=0;
char f[105][105];
inline bool check(int x,int y){
	return x>=0&&y>=0&&x<=a&&y<=b;
}
int dfs(int x,int y){
	if(check(x,y)&&f[x][y]=='#'){
		f[x][y]='.';
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x-1,y);
		dfs(x,y-1);
		return 1;
	}else return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ans=0;memset(f,0,sizeof(f));
		cin>>a>>b;
		for(int i=0;i<a;i++){
			cin>>f[i];
		}
		for(int i=0;i<=a;i++){
			for(int j=0;j<=b;j++){
				if(dfs(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
}
