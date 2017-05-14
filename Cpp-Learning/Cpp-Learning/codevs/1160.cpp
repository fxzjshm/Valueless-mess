#include <bits/stdc++.h>
namespace p1160{
using namespace std;
int n,ns[100][100],dx[]={1,0,-1,0},dy[]={0,-1,0,1},nd[]={1,2,3,0},sum=0;
int main1160(){
    cin>>n;
    memset(ns,0,sizeof(ns));
    int x=n/2,y=n/2,d=0;//R=0,U=1,L=2,D=3
    for(int i=1;i<=n*n;i++){
        ns[x][y]=i;
        x+=dx[d];
        y+=dy[d];
        if(0==ns[x+dx[nd[d]]][y+dy[nd[d]]])
            d=nd[d];
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++)
            printf("%d ",ns[i][j]);
        sum+=ns[j][j];
        sum+=ns[j][n-j-1];
        printf("\n");
    }
    sum-=ns[n/2][n/2];
    printf("%d",sum);
    return 0;
}
}
