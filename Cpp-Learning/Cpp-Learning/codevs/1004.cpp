#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
namespace p1004{
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int b[5][5],o1x,o1y,o2x,o2y,deplim,a=0;
char t;
/*
inline void print(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout<<b[i][j];
		}
		cout<<endl;
	}
}
*/
inline int toInt(char c){// B==1,W==2,O==0;
	if(c=='B')return 1;
	if(c=='W')return 2;
	else return 0;
}
inline void check(){
	for(int i=1;i<=4;i++){
		if(b[1][i]==b[2][i]&&b[2][i]==b[3][i]&&b[3][i]==b[4][i])a=1;
		if(b[i][1]==b[i][2]&&b[i][2]==b[i][3]&&b[i][3]==b[i][4])a=1;
	}
	if(b[1][1]==b[2][2]&&b[2][2]==b[3][3]&&b[3][3]==b[4][4])a=1;
	if(b[1][4]==b[2][3]&&b[2][3]==b[3][2]&&b[3][2]==b[4][1])a=1;
}
inline bool check(int a,int c,int pre){
	return a>0&&a<=4&&c>0&&c<=4&&(b[a][c]!=pre);
}
void dfs(int depth,int& x,int& y,int pre){
	check();
	if(a||depth>deplim)return;
	int x1,y1,bx,by;
	for(int s=0;s<4;s++){
		x1=x+dx[s];
		y1=y+dy[s];
		if(check(x1,y1,pre)){
			bx=x;by=y;
			swap(b[x][y],b[x1][y1]);
			x=x1;y=y1;
			check();
			if(a==1){
				return;
			}
			dfs(depth+1,o1x,o1y,(pre==1)?2:1);
			dfs(depth+1,o2x,o2y,(pre==1)?2:1);
			x=bx;y=by;
			swap(b[x][y],b[x1][y1]);
		}
	}
}
int main(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>t;
			b[i][j]=toInt(t);
			if(b[i][j]==0){
				if(o1x){
					o2x=i;
					o2y=j;
				}else{
					o1x=i;
					o1y=j;
				}
			}
		}
	}
	check();
	if(a){
		cout<<0;
		return 0;
	}
	for(deplim=1;a==0;deplim++){
		dfs(1,o1x,o1y,1);
		dfs(1,o1x,o1y,2);
		dfs(1,o2x,o2y,1);
		dfs(1,o2x,o2y,2);
	}
	cout<<deplim-1;
	return 0;
}
}
