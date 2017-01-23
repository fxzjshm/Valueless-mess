#include<bits/stdc++.h>

using namespace std;
bool isNotFactable(long n){
    if(n%2==0) // 2
            return false;
    double maxNum=sqrt(n);
    for(unsigned long i=3;i<=maxNum;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int ch011311(){
    unsigned int l,l2;
    cin>>l;
    if(l==1){
        cout<<"4"<<endl;
        cout<<"2 3 5 7";
        return 0;
    }
    if(l==2){
        cout<<"1"<<endl;
        cout<<"11";
        return 0;
    }
    if(l%2==0){
        cout<<"0"<<endl;
        return 0;
    }
    long nums[5173];
    int numSize=0;
    l2=(l-1)/2;
    long long num,num2,base=pow(10,l2),basel=base/10;
    int temp;
    for(int i=basel;i<base;i++){
        num=i*10;
        temp=i;
        while(temp){
            num*=10;
            num+=temp%10;
            temp/=10;
        }
        for(int j=0;j<=9;j++){
            num2=num+j*base;
            if(isNotFactable(num2)){
                nums[numSize]=num2;
                numSize++;
            }
        }
    }
    cout<<numSize<<endl;
    for(unsigned int i=0;i<numSize;i++){
        printf("%d ",nums[i]);
        // if(i!=nums.size()-1)cout<<" ";
    }
    return 0;
}
