#include<vector>
#include<cstdio>
namespace p1294_2{
using namespace std;
int n,used[12],ns[12];
struct stk{
	int k,i;
};
vector<stk> ss;
int main(){
	scanf("%d",&n);
	int i,k=1;
	ST:;
	for(i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			ns[k]=i;
			if(k==n){
				for(int j=1;j<=n;j++){
					printf("%d ",ns[j]);
				}
				printf("\n");
			}else{
				stk s;
				s.k=k;
				s.i=i;
				ss.push_back(s);
				k=k+1;
				goto ST;
				ED:;
				if(ss.size()){
					stk t=ss[ss.size()-1];
					ss.pop_back();
					k=t.k;
					i=t.i;
				}else goto RE;
			}
			used[i]=0;
		}
	}
	goto ED;
	RE:return 0;
}
}
