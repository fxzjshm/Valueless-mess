#include<iostream>
#include<vector>
using namespace std;
namespace pp3254{
int m,n;
long long dp[13][1<<13],ans;
vector<long long> valid[13];// valid[line][0..size()]
inline bool checkline(int i,int mask){
    return (!(i&mask))&&(!((i<<1)&i));
}
inline bool checklines(int i,int j){
    return (!(i&j));
}
int main(){
	cin>>m>>n;
	int t,mask;
	for(int i=0;i<m;i++){
		mask=0;
		for(int j=0;j<n;j++){
			cin>>t;
			t^=1;
			mask|=t;
			mask<<=1;
		}
		mask>>=1;
		for(int k=0;k<(1<<n);k++){
			if(checkline(k,mask)){
				valid[i].push_back(k);
			}
		}
	}
	for(int i=0;i<valid[0].size();i++){
        dp[0][valid[0][i]]=1;
	}
	for(int line=1;line<m;line++){
        for(int indn1=0;indn1<valid[line-1].size();indn1++){
            int j=valid[line-1][indn1];
            for(int indi=0;indi<valid[line].size();indi++){
                int i=valid[line][indi];
                if(checklines(i,j)){
                    dp[line][i]=(dp[line-1][j]+dp[line][i])%100000000;
                }
            }
        }
	}
	/*
	for(int line=0;line<m;line++){
        for(int indn1=0;indn1<valid[m-1].size();indn1++){
            int j=valid[m-1][indn1];
            cout<<dp[line][j]<<' ';
        }
        cout<<endl;
	}
	*/
	ans=0;
	for(int indi=0;indi<valid[m-1].size();indi++){
	    ans=(ans+dp[m-1][valid[m-1][indi]])%100000000;
	}
	cout<<ans;
	return 0;
}
}
