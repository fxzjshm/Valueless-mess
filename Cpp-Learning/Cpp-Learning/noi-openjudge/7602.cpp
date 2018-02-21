#include <bits/stdc++.h>
using namespace std;
namespace p7602{
inline char cg(char c){
    if('a'<=c&&c<='z')return c-'a'+'A';
    else return c;
}
inline void p(char c,int i){
    printf("(%c,%d)",c,i);
}
int main(){
    string s;
    cin>>s;
    int n=1;
    s[0]=cg(s[0]);
    for(int i=1;i<s.size();i++){
        s[i]=cg(s[i]);
        if(s[i]==s[i-1])n++;
        else{
            p(s[i-1],n);
            n=1;
        }
    }
    p(s[s.size()-1],n);
    return 0;
}
}
