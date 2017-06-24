#include<iostream>
#include<vector>
using namespace std;
namespace p1380{
int n,ri,l,k,root;
int dp[2][6005],r[6005];
bool isRoot[6005];
vector<int> sub[6005];
/*sub[root][x]=child*/
void dfs(int x){
	dp[1][x]=r[x];
	vector<int> childs=sub[x];
	for(int i=0;i<sub[x].size();i++){
		int child=sub[x][i];
		dfs(child);
		dp[1][x]+=dp[0][child];
		dp[0][x]+=max(dp[0][child],dp[1][child]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ri;
		r[i]=ri;
		dp[1][i]=ri;
		isRoot[i]=true;
	}
	while(1){
		cin>>l>>k;
		if(l==0&&k==0)break;
		sub[k].push_back(l);
		isRoot[l]=false;
	}
	for(int i=1;i<=n;i++){
		if(isRoot[i]){
			root=i;
			break;
		}
	}
	dfs(root);
	cout<<max(dp[0][root],dp[1][root]);
	return 0;
}
}
