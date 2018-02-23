#include <bits/stdc++.h>
namespace pnoi2971{
using namespace std;
const int maxn=100005;
struct node{
	int i,s;
};
deque<node> q;
bool used[maxn];
int n,k;
int main(){
	cin>>n>>k;
	node ni;
	ni.i=n;
	ni.s=0;
	q.push_back(ni);
	while(1){
		// assert(!q.empty());
		node x=q.front();
		used[x.i]=1;
		if(x.i==k){
			cout<<x.s;
			break;
		}
		/*for(int i=1;i<q.size();i++){
			cout<<q[i].i<<' ';
		}
		cout<<endl;*/
		q.pop_front();
		node n1,n2,n3;
		n1.s=n2.s=n3.s=x.s+1;
		int i1=x.i*2,i2=x.i-1,i3=x.i+1;
		if(i1>=0&&i1<maxn&&!used[i1]){
			n1.i=i1;
			q.push_back(n1);
		}
		if(i2>=0&&i2<maxn&&!used[i2]){
			n2.i=i2;
			q.push_back(n2);
		}
		if(i3>=0&&i3<maxn&&!used[i3]){
			n3.i=i3;
			q.push_back(n3);
		}
	}
	return 0;
}
}
