// not completed!
#include<cstdio>
#include<algorithm>
#include<memory.h>
#define MXS
using namespace std;
namespace p1880{
long long n,sum[2005],mns[2005][2005],mn=0x7FFFFFFF,mx;
#ifdef MXS
long long mxs[2005][2005];
#endif /*MXS*/
int main(){
	memset(mns,0x3f,sizeof(mns));
	#ifdef MXS
	memset(mxs,0,sizeof(mxs));
	#endif /*MXS*/
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&sum[i]);
		mns[i][i]=0;
		sum[i]+=sum[i-1];
		#ifdef MXS
		mxs[i][i]=0;
		#endif /*MXS*/
	}
	for(int i=n+1;i<=2*n;i++){
		sum[i]=sum[n]+sum[i-n];
	}
	for(int st=1;st<=2*n;st++){
		// mns[st][st]=sum[st]-sum[st-1];
		mns[st][st+1]=sum[st+1]-sum[st-1];
		#ifdef MXS
		// mxs[st][st]=sum[st]-sum[st-1];
		mxs[st][st+1]=sum[st+1]-sum[st-1];
		#endif /*MXS*/
	}
	for(int len=2;len<=n;len++){
		for(int st=1;st+len-1<=2*n;st++){
			int ed=st+len-1;
			// mns[st][ed]=0x7f7f7f7f;
			for(int sp=st;sp<ed;sp++){
				mns[st][ed]=min((mns[st][sp]+mns[sp+1][ed]+sum[ed]-sum[st-1]),mns[st][ed]);
				#ifdef MXS
				mxs[st][ed]=max((mxs[st][sp]+mxs[sp+1][ed]+sum[ed]-sum[st-1]),mxs[st][ed]);
				#endif /*MXS*/
			}
		}
	}

	for(int i=1;i<=n;i++){
		mn=min(mn,mns[i][i+n-1]);
		#ifdef MXS
		mx=max(mx,mxs[i][i+n-1]);
		#endif /*MXS*/
	}
	printf("%lld\n",mn);
	#ifdef MXS
	printf("%lld",mx);
	#endif /*MXS*/
	return 0;
}
}
