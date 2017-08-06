#include<bits/stdc++.h>
using namespace std;
namespace ph2089{
int m,n,d[10],dp[10][10];
void init(){
    dp[0][0]=1;
    for(int i=1;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(j==4)continue;
            for(int k=0;k<=9;k++){
                if(j==6&&k==2)continue;
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int work(int m){
    memset(d,0,sizeof(d));
    int len=1,ans=0;
    while(m){
        d[len]=m%10;
        len++;
        m/=10;
    }
    for(int i=len;i>0;i--){
        for(int j=0;j<d[i];j++){
            if(d[i+1]==6&&j==2)continue;// ???
            if(j==4)continue;
            ans+=dp[i][j];
        }
        if(d[i]==4||(d[i+1]==6&&d[i]==2))break;
    }
    return ans;
}
int main(){
    init();
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        printf("%d\n",work(m+1)-work(n));
    }
    return 0;
}
}
