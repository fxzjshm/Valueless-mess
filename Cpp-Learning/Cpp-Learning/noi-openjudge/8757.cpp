#include <bits/stdc++.h>
using namespace std;
namespace pnoi8757{
inline bool check(int a,int b,int c){
    string s;
    map<char,int> mp;
    stringstream ss;
    ss<<a<<b<<c;
    ss>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')return false;
        if(mp.count(s[i]))return false;
        mp[s[i]]++;
    }
    return true;
}
int main(){
    for(int i=100;i<1000;i++){
        if(check(i,2*i,3*i)){
            cout<<i<<' '<<2*i<<' '<<3*i<<endl;
        }
    }
    return 0;
}
}
