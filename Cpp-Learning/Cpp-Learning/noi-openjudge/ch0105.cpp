#include<bits/stdc++.h>

using namespace std;

int ch010501() {
	int num=0,sum=0,temp=0;
	cin >> num;
	for (int i=0;i<num;i++){
		cin >> temp;
		sum += temp;
	}
	printf("%.2f", 1.0*sum/num);
	return 0;
}

int ch010502() {
	double sum=0,temp=0;
	for (int i=0;i<12;i++){
		cin >> temp;
		sum += temp;
	}
	printf("$%.2f", sum/12);
	return 0;
}

int ch010503() {
	double num=0,sum=0,temp=0;
	cin >> num;
	for (int i=0;i<num;i++){
		cin >> temp;
		sum += temp;
	}
	printf("%.4f", 1.0*sum/num);
	return 0;
}

int ch010504(){
    int n,sum=0,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        sum+=temp;
    }
    cout<<sum;
    printf(" %.5f",1.0*sum/n);
    return 0;
}

int ch010505(){
    int n,m=0,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        m=max(m,temp);
    }
    cout<<m;
    return 0;
}

int ch010506(){
    int n,ma=0,temp,mi;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        ma=max(ma,temp);
        mi=min(mi,temp);
    }
    cout<<ma-mi;
    return 0;
}


int ch010507(){
    int n,au=0,ag=0,cu=0,t1,t2,t3;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t1>>t2>>t3;
        au+=t1;
        ag+=t2;
        cu+=t3;
    }
    cout<<au<<" "<<ag<<" "<<cu<<" "<<au+ag+cu;
    return 0;
}

int ch010508(){
    int n,m,t;
    cin>>n;
    m=(n-2)*180;
    for(int i=0;i<n-1;i++){
        cin>>t;
        m-=t;
    }
    cout<<m;
    return 0;
}

int ch010509(){
    int a,b,s=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
        if(i%2)s+=i;
    cout<<s;
    return 0;
}

int ch010510(){
    int a,b,s=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
        if(0==i%17)s+=i;
    cout<<s;
    return 0;
}

int ch010511(){
	int k,n1=0,n5=0,n10=0,t;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>t;
		if(1==t)n1++;
		if(5==t)n5++;
		if(10==t)n10++;
	}
	cout<<n1<<endl<<n5<<endl<<n10;
	return 0;
}

int ch010512(){
	int k,n=0,t,m;
	cin>>k>>m;
	for(int i=0;i<k;i++){
		cin>>t;
		if(m==t)n++;
	}
	cout<<n;
	return 0;
}
