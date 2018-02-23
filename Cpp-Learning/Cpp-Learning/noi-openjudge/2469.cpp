#include <bits/stdc++.h>
using namespace std;
namespace pnoi2469{
const int maxn=1005;
int a[maxn],s[maxn],n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		printf("%.1f\n",((a[n]>s[n-1])?((double)(s[n-1])):(((double)s[n])/2)));
	}

	return 0;
}
}
