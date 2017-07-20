#include<cstdio>
using namespace std;
namespace p1082{
int n,t,q,a,b;
long long /*ns[200005],*/as[400005],x;
inline int lowbit(int x){
    return x&(-x);
}
inline void update(int ind,int delta){
    while(ind<=n){
        as[ind]+=delta;
        ind+=lowbit(ind);
    }
}
inline long long sum(int ind){
    long long s=0;
    while(ind){
        s+=as[ind];
        ind-=lowbit(ind);
    }
    return s;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        update(i,t);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&t,&a,&b);
        if(t==1){
            scanf("%d",&x);
            for(int j=a;j<=b;j++){
                update(j,x);
            }
        }else{
            printf("%lld\n",sum(b)-sum(a-1));
        }
    }
    return 0;
}
}
#include<bits/stdc++.h>
namespace p1082_gen{
long long is[200000],ans[200000];
int gen(){
    freopen("1082.in","w",stdout);
    cout<<200000<<endl;
    for(int i=0;i<200000;i++){
        is[i]=rand();
        printf("%d ",is[i]);
    }
    int a,b;
    for(int k=0;k<100000;k++){
        regen1:;
        a=floor(rand()%200000);
        b=floor(rand()%200000);
        if(a>b)goto regen1;
        long long x=floor(rand()%(1<<16));
        printf("1 %d %d %d\n",a,b,x);
        for(int i=a;i<=b;i++){
            is[i]+=x;
        }
    }
    for(int k=0;k<100000;k++){
        regen2:;
        a=floor(rand()%200000);
        b=floor(rand()%200000);
        if(a>b)goto regen2;
        printf("2 %d %d\n",a,b);
        long long sum=0;
        for(int i=a;i<=b;i++){
            sum+=is[i];
        }
        ans[k]=sum;
    }
    printf("\n\n\n");
    for(int k=0;k<100000;k++){
        printf("%d\n",ans[k]);
    }
    fclose(stdout);
}
}
int main(){
    p1082::main();
    // p1082_gen::gen();
    return 0;
}
