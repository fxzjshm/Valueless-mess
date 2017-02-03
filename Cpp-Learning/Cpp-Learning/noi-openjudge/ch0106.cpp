#include <bits/stdc++.h>
using namespace std;

int ch010601(){
    int l,t,n,a=0;
    cin>>l;
    long long ns[l];
    for(int i=0;i<l;i++){
        cin>>t;
        ns[i]=t;
    }
    cin>>n;
    for(int i=0;i<l;i++)
        if(ns[i]==n)a++;
    cout<<a;
    return 0;
}

int ch010602(){
    int t,n,a=0;
    long long ns[10];
    for(int i=0;i<10;i++){
        cin>>t;
        ns[i]=t;
    }
    cin>>n;
    for(int i=0;i<10;i++)
        if(ns[i]<=n+30)a++;
    cout<<a;
    return 0;
}

int ch010603(){
    double m[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
    int t;
    double a=0;
    for(int i=0;i<10;i++){
        cin>>t;
        a+=t*m[i];
    }
    printf("%.1f",a);
    return 0;
}
