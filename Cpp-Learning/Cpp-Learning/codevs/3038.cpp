#include <bits/stdc++.h>
namespace p3038{
using namespace std;
int main(){
    int t,s=0,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        while(n!=1){
            if(n&1)n=3*n+1;
            else n/=2;
            s++;
        }
        cout<<s<<endl;
        s=0;
    }
    return 0;
}
}
