#include <bits/stdc++.h>
using namespace std;
namespace pnoi2179{
const int maxn=1005;
bool ls[maxn];
int main(){
    int n;
    cin>>n;
    memset(ls,1,sizeof(ls));
    for(int p=1;p<=n;p++){
        for(int i=p;i<=n;i+=p){
            ls[i]=(!ls[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(ls[i])cout<<i<<' ';
    }
    return 0;
}
}
