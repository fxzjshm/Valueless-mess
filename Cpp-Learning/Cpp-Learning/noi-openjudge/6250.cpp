#include <bits/stdc++.h>
using namespace std;
namespace p6250{
string s0,s,s1,s2;
inline void init(){
    int i=0;
    for(;i<s0.size();i++){
        if(s0[i]!=',')s+=s0[i];
        else break;
    }
    for(i++;i<s0.size();i++){
        if(s0[i]!=',')s1+=s0[i];
        else break;
    }
    for(i++;i<s0.size();i++){
        if(s0[i]!=',')s2+=s0[i];
        else break;
    }
}
int main(){
    cin>>s0;
    init();
    int st=-1,ed=-1;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s1.size();j++){
            if(s[i+j]!=s1[j])goto CO1;
        }
        st=i+s1.size()-1;
        break;
        CO1:continue;
    }
    for(int i=s.size()-s2.size();i>=0;i--){
        for(int j=s2.size()-1;j>=0;j--){
            if(s[i+j]!=s2[j])goto CO2;
        }
        ed=i;
        break;
        CO2:continue;
    }
    // cout<<st<<' '<<ed<<endl;
    if(st!=-1&&ed!=-1&&st<ed)cout<<(ed-st-1);
    else cout<<-1;
    return 0;
}
}
