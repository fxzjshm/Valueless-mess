#include<bits/stdc++.h>
using namespace std;
namespace p1082_2{
int n,q,a,b,x,m;
long long as[200005];
struct node{
	int l,r;
	long long sum,lazy;
}tr[800005];
void print(int i){
	printf("index=%d,l=%d,r=%d,sum=%d,lazy=%d\n",i,tr[i].l,tr[i].r,tr[i].sum,tr[i].lazy);
}
void build(int i,int s,int t){
	tr[i].l=s;
	tr[i].r=t;
	int mid=(s+t)>>1;
	if(s==t){
		tr[i].sum=as[s];
		return;
	}
	build(i<<1,s,mid);
	build((i<<1)|1,mid+1,t);
	tr[i].sum=tr[i<<1].sum+tr[(i<<1)|1].sum;
}
void pushdown(int i){
	if(tr[i].lazy!=0&&(tr[i].l!=tr[i].r)){

		int l=i<<1,r=(i<<1)|1;
		tr[l].lazy+=tr[i].lazy;// = -> +=
		tr[r].lazy+=tr[i].lazy;//
		tr[l].sum+=tr[i].lazy*(tr[l].r-tr[l].l+1);
		tr[r].sum+=tr[i].lazy*(tr[r].r-tr[r].l+1);
		tr[i].sum=tr[l].sum+tr[r].sum;
		tr[i].lazy=0;
	}

}
void update(int i,int a,int b,long long x){
	// printf("i=%d,a=%d,b=%d,x=%d\n",i,a,b,x);
	pushdown(i);
	if(tr[i].l==a&&tr[i].r==b){
		tr[i].sum+=(b-a+1)*x;
		tr[i].lazy=x;
	}else{
		int mid=(tr[i].l+tr[i].r)>>1;
		if(b<=mid)update(i<<1,a,b,x);
		else if(a>mid)update((i<<1)|1,a,b,x);
		else{
			update(i<<1,a,mid,x);
			update((i<<1)|1,mid+1,b,x);
		}
		tr[i].sum=tr[i<<1].sum+tr[(i<<1)|1].sum;
	}
}
long long get(int i,int a,int b){
	pushdown(i);
	if(tr[i].l==a&&tr[i].r==b)return tr[i].sum;
	else{
		int mid=(tr[i].l+tr[i].r)>>1;
		if(b<=mid)return get(i<<1,a,b);
		else if(a>mid)return get((i<<1)|1,a,b);
		else return get(i<<1,a,mid)+get((i<<1)|1,mid+1,b);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&as[i]);
	}
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&m);
		scanf("%d",&a);
		scanf("%d",&b);
		if(1==m){
			scanf("%d",&x);
			update(1,a,b,x);
		}else{
			printf("%lld\n",get(1,a,b));// %d -> %lld
		}
		/*for(int i=1;i<=2*n;i++){
			print(i);
		}*/
	}
	return 0;
}
}
