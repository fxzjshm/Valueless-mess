#include <bits/stdc++.h>
namespace p1212{
using namespace std;
int gcd(int i,int j){
    return (i%j)?gcd(j,i%j):j;
}
int main1212(){
    int i,j;
    cin>>i>>j;
    cout<<gcd(max(i,j),min(i,j));
    return 0;
}
}
