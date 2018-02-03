#include <iostream>
using namespace std;
namespace p8181{
int main(){
    unsigned long long i;
    cin>>i;
    cout<<(i%10);
    i/=10;
    while(i){
        cout<<' '<<(i%10);
        i/=10;
    }
    return 0;
}
}
