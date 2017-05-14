#include <bits/stdc++.h>
namespace p1978{
using namespace std;
long long f(int n){
    if(n<3)return 1;
    return f(n-1)+f(n-2);
}
int main1978(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
}
