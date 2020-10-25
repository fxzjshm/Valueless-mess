#include<iostream>
#include<cstring>
using namespace std;
namespace pp1050{
const int MAX_N=105;

int a[MAX_N][MAX_N];
int preSx[MAX_N][MAX_N],preSy[MAX_N][MAX_N];
int N;
int maxS=0x80000000;

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	memset(preSx,0,sizeof(preSx));
	memset(preSy,0,sizeof(preSy));

	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>t;
			a[i][j]=t;
			// fp[1][i][j]=t;
			maxS=max(maxS,t);
			preSx[i][j]=preSx[i][j-1]+t;
			preSy[j][i]=preSy[j][i-1]+t;
		}
	}

	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			for(int lx=1;lx<=N-x+1;lx++){
				t=preSy[y][x+lx-1]-preSy[y][x-1];
				maxS=max(maxS,t);
				for(int ly=2;ly<=N-y+1;ly++){
					t+=preSy[y+ly-1][x+lx-1]-preSy[y+ly-1][x-1];
					maxS=max(maxS,t);
				}
			}
		}
	}
	cout<<maxS<<endl;
	return 0;
}
}
