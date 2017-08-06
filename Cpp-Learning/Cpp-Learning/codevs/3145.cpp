#include <bits/stdc++.h>
using namespace std;
namespace p3145{
int n;
inline void print(int i,char a,char c){
    printf("%d from %c to %c\n",i,a,c);
}
void work(int m/*,int i*/,char a,char b,char c){
    if(m==1){
        print(/*i*/1,a,c);
        return;
    }
    work(m-1,a,c,b);
    print(m,a,c);
    work(m-1,b,a,c);
}
int main(){
    scanf("%d",&n);
    printf("%lld\n",(1L<<n)-1);
    work(n,'A','B','C');
    return 0;
}
}
