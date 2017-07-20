#include <bits/stdc++.h>
using namespace std;
inline bool check(int a,int b,int c){
    string s;
    map<char,int> mp;
    stringstream ss;
    ss<<a<<b<<c;
    ss>>s;
    for(int i=0;i<s.size();i++){
        if(mp.count(s[i]))return false;
        mp[s[i]]++;
    }
    return true;
}
int main(){
    bool b=false;
    for(int i=100;i<1000;i++){
        if(check(i,2*i,3*i)){
            if(!b){
                b=true;
            }else{
                cout<<endl;
            }
            cout<<i<<' '<<2*i<<' '<<3*i;
        }
    }
    return 0;
}
/*
int main(){

    return 0;
}
*/
