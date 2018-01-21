#include<iostream>
using namespace std;
namespace nowcoder_67F{
int main(){
    int T,a,b,c,d,l;
    cin>>T;
    for(int T1=1;T1<=T;T1++){
        cin>>a>>b>>c;
        d=b;
        l=100;
        for(int t=0;t+1;t++){
            // printf("t=%d,d=%d,l=%d\n",t,d,l);
            if(l<=0&&d>0)goto NO;
            if(l/a*1>=d)goto YES;
            if(l>6*a&&(l-a)<=6*a&&l<80&&c>0){
                t+=6-1;
                l=80;
                c--;
                continue;
            }
            d--;
            l-=a;
        }
        YES:cout<<"YES"<<endl;
        continue;
        NO:cout<<"NO"<<endl;
    }

    return 0;
}
}
/*int main(){
    return nowcoder_67F::main();
}*/
