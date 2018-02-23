#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
namespace pnoi011311buggy{
using namespace std;
bool isNotFactable(unsigned long n){
    if(n<2)return false;
    double max=sqrt(n);
    for(unsigned long i=2;i<=max;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int getBits(long long n){
    n=abs(n);
    int m=0;
    for(;n>0;n/=10)m++;
    return m;
}
int getBit(long long n,int m){
    long long a,b;
    for(;getBits(n)!=m;n/=10);
    a=n;
    b=a/10;
    return a-b*10;
}
int main(){
    unsigned int l,l2,n;
    cin>>l;
    if(l==2){
        cout<<"1"<<endl;
        cout<<"11";
        return 0;
    }
    if(l%2==0){
        cout<<"0"<<endl;
        return 0;
    }
    vector <long long> nums;
    l2=(l-1)/2;
    for(int i=pow(10,l2);i<pow(10,l2+1)-1;i++){
        long long num=i*pow(10,getBits(i)-1);
        for(int j=1;j<getBits(i);j++){
            num+=pow(10,j-1)*getBit(i,j);
        }
        if(getBits(num)!=3&&getBits(num)!=1&&getBits(num)!=7){
            num+=1;
        }
        if(isNotFactable(num)){
            nums.push_back(num);
        }
    }
    cout<<nums.size()<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
        if(i!=nums.size()-1)cout<<" ";
    }
    return 0;
}
}
