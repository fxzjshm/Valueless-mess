#include <bits/stdc++.h>
using namespace std;
namespace p8170{
string eml0,usr,pwd,eml;
int n,f=1;
inline string c(string o){
    f=0;
    string r;
    for(int i=0;i<o.size();i++){
        if('a'<=o[i]&&o[i]<='z')r+=o[i]-'a'+'A';
        else if('A'<=o[i]&&o[i]<='Z')r+=o[i]-'A'+'a';
        else r+=o[i];
    }
    return r;
}
int main(){
    cin>>eml0;
    cin>>n;
    while(n--){
        cin>>usr>>pwd>>eml;
        if(eml==eml0){
            cout<<usr<<' '<<c(pwd)<<endl;
        }
    }
    if(f)cout<<"empty";
    return 0;
}
}
