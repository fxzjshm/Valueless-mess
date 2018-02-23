#include <bits/stdc++.h>
using namespace std;
namespace pnoi2705{
string s;
vector<int> stk,is;
int main(){
    while(getline(cin,s)){
        stk.clear();
        is.clear();
        int l=s.size();
        for(int i=0;i<l;i++){
            if(s[i]=='('){
                stk.push_back(i);
            }else if(s[i]==')'){
                if(stk.empty()){
                    is.push_back(i);
                }else{
                    stk.pop_back();
                }
            }
        }
        cout<<s<<endl;
        l=is.size();
        int last=-1;
        for(int i=0;i<l;i++){
            for(int j=0;j<is[i]-last-1;j++)printf(" ");
            printf("?");
            last=is[i];
        }
        l=stk.size();
        for(int i=0;i<l;i++){
            for(int j=0;j<stk[i]-last-1;j++)printf(" ");
            printf("$");
            last=stk[i];
        }
        printf("\n");
    }
    return 0;
}
}
