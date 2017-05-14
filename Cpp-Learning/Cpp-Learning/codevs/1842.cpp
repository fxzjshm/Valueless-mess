#include <bits/stdc++.h>
namespace p1842{
using namespace std;
long long f(int n){
    if(n>=0)return 5;
    return f(n+1)+f(n+2)+1;
}
int main1842(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
}
