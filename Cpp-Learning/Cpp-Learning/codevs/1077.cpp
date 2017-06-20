#include <bits/stdc++.h>
namespace p1077{
using namespace std;
int ns[105][105],n,q,a,b;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&ns[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ns[i][j]=min(ns[i][j],ns[i][k]+ns[k][j]);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",ns[a][b]);
    }
    return 0;
}
}

