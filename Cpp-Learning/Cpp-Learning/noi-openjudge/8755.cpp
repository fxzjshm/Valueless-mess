#include<iostream>
using namespace std;
namespace pnoi8755{
int n1,n2,n3,n5,n10,n20,t,ans=0,ns[1005];
int main(){
	cin>>n1>>n2>>n3>>n5>>n10>>n20;
	for(int i1=0;i1<=n1;i1++){
		for(int i2=0;i2<=n2;i2++){
			for(int i3=0;i3<=n3;i3++){
				for(int i5=0;i5<=n5;i5++){
					for(int i10=0;i10<=n10;i10++){
						for(int i20=0;i20<=n20;i20++){
							t=i1+2*i2+3*i3+5*i5+10*i10+20*i20;
							if(!ns[t]){
								ns[t]=1;
								ans++;
							}
						}
					}
				}
			}
		}
	}
	cout<<"Total="<<ans-1;
	return 0;
}
}
