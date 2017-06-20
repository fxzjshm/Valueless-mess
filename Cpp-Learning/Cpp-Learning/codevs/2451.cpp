// -----------BUGGY!-----------
#include <bits/stdc++.h>
namespace p2451{
using namespace std;
int N,K,lines[1025],nking[1025],nlist,a=0,ans[10];
int getKings(int i){
    int n=0;
    while(i!=0){
        n+=i&1;
        i=i>>1;
    }
    return n;
}
void init(){
    int i=0,n,maxn=int(pow(2,N))-1;
    while(i<maxn){
        n=getKings(i);
        if(n<=N){
            if(((i<<1)&i)==0&&((i>>1)&i)==0){
                lines[nlist]=i;
                nking[nlist]=n;
                nlist++;
            }
            i++;
        }else{
            break;
        }
    }
}
void dfs(int last,int lastn,int depth){
    int cur,nown;
    for(int i=0;i<nlist;i++){
        nown=nking[i]+lastn;
        if(nown<=K){
            cur=lines[i];
            if(((cur&last)==0)
            &&(((cur<<1)&last)==0)
            &&(((cur>>1)&last)==0)){
                ans[depth-1]=cur;
                if(depth==N){
                    if(nown==K){
                        a++;
                    }else{
                        continue;
                    }
                }else{
                    dfs(i,nown,depth+1);
                }
            }
        }
    }
}
int main(){
    cin>>N>>K;
    init();
    //dfs(0,0,1);
    dfs(4,1,2);
    cout<<a;
    return 0;
}
}
