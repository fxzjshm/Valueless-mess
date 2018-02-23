#include <bits/stdc++.h>
namespace pnoi2729{
using namespace std;
deque<long long> q;
int a,n;
int main(){
	while(cin>>a>>n){
	q.clear();
	int l1=0,l2=0;
	q.push_back(a);
	while(q.size()<n){
		int x=q[l1]*2+1,y=q[l2]*3+1;
		if(x<y){
			q.push_back(x);
			l1++;
		}else if(x>y){
			q.push_back(y);
			l2++;
		}else{
			q.push_back(x);
			l1++;
			l2++;
		}
	}
	cout<<q[n-1]<<endl;
	}
	return 0;
}
}
