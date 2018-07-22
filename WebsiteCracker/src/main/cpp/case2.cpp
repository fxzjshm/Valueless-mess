#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
using namespace std; char *rand_num(char *str,const int len) {
     srand(time(NULL));
    int i;
    for(i=0;i<len;++i)
    {
        str[i]='0'+rand()%10;
    }
     str[++i]='\0';
    return str;
}
char *rand_str(char *str,const int len) {
     srand(time(NULL));
    int i;
    for(i=0;i<len;++i)
    {
         switch((rand()%3))
         {
         case 1:
        str[i]='A'+rand()%26;
       break;
        case 2:
        str[i]='a'+rand()%26; break;
     default:
        str[i]='0'+rand()%10;
       break;
         }
    }
     str[++i]='\0';
    return str;
}
int main(void) {
	const int accs=10,pwds=10;
    char acc[accs], pwd[(pwds)], cce[pwds];
    string cmd;
    stringstream ss;
    while(1){
    ss.clear();
    rand_num(acc,accs);
    rand_str(pwd,pwds-1);
    ss<<"curl -d \"u=";
    ss<<acc;
    ss<<"&p=";
    ss<<pwd;
    ss<<"\" http://www.j-qzcom.top/qzone_red/root.php";
    getline(ss,cmd);
    cout<<cmd<<endl;
    system(cmd.c_str());
    cmd.clear();
    sleep(1);
	}
 return 0;
}
