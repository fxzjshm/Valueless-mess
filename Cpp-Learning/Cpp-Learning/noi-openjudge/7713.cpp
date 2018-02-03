#include <iostream>
using namespace std;
namespace p7713{
int main(){
    double d,a,b;
    cin>>d;
    a=27+23+(d/3.0);
    b=d/1.2;
    if(a>b)cout<<"Walk";
    else if(a==b)cout<<"All";
    else cout<<"Bike";
    return 0;
}
}
