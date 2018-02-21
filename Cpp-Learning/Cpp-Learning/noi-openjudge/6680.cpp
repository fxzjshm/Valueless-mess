#include <bits/stdc++.h>
using namespace std;
// namespace p6680{
inline void p(char c,int i){
    printf("%d%c",i,c);
}
int main(){
    string s;
    cin>>s;
    int n=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])n++;
        else{
            p(s[i-1],n);
            n=1;
        }
    }
    p(s[s.size()-1],n);
    return 0;
}
// }
