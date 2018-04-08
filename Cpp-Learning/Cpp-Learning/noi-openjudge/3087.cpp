//WA
#include <bits/stdc++.h>
namespace pnoi3087{
using namespace std;
string s;
int main(){
    while(getline(cin,s)){
    while(s[0]==' ')s.erase(0,1);
        int i1=s.find_first_of('@'),
            i2=s.find_last_of('@'),
            j1=s.find_first_of('.'),
            j2=s.find_last_of('.'),
            l=s.size();
        if(i1==i2&&i1!=0&&j1!=0&&i2!=l-1&&j2!=l-1&&j2>i1&&s[i1+1]!='.'){
            cout<<"YES";
        }else cout<<"NO";
        cout<<endl;
    }
    return 0;
}
}
