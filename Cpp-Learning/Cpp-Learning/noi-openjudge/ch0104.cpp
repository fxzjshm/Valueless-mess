#include<bits/stdc++.h>

using namespace std;

int ch010401() {
    double n;
    cin >> n;
    if(n>0)
        cout << "positive";
    if(n==0)
        cout << "zero";
    if(n<0)
        cout << "negative";

    return 0;
}

int ch010402()
{
    double n;
    cin >> n;
    if(n>=0)
        ;
    if(n<0)
        n=-n;
    printf("%.2f",n);

    return 0;
}

int ch010403()
{
    unsigned long n;
    cin >> n;
    if(n%2==0)
        cout << "even";
    if(n%2==1)
        cout << "odd";

    return 0;
}

int ch010404()
{
    //Something went wrong with ' ' (space), you know.
    int n=getchar();
    if(n%2==0)
        cout << "NO";
    if(n%2==1)
        cout << "YES";

    return 0;
}

int ch010405(){
	double a;
	double b;

	cin >> a >> b;
	if(a>b)
		cout << ">";
	if(a==b)
	    cout << "=";
	if(a<b)
	    cout << "<";

    return 0;
}

int ch010406(){
	double a;

	cin >> a;
	if(9<a && a<100)
	    cout << 1;
	else
	    cout << 0;

    return 0;
}

int ch010407(){
	double a,b;

	cin >> a >> b;
	if(a>=10||b>=20)
	    cout << 1;
	else
	    cout << 0;

    return 0;
}

int ch010408(){
	long long a;
	cin >> a;
	if(a%3==0&&a%5==0)
	    cout << "YES";
	else
	    cout << "NO";

    return 0;
}

int ch010409(){
	long long a;
	bool o=false;
	cin >> a;
	if(a%3==0){
		cout << 3;
		o=true;
	}
	if(a%5==0){
		if(o==true)
		    cout << " ";
		cout << 5;
		o=true;
	}
	if(a%7==0){
		if(o==true)
		    cout << " ";
		cout << 7;
		o=true;
	}
	if(!o)
	    cout << "n";

    return 0;
}

int ch010410(){
    int a,b;
	cin >> a >> b;
    if(a<60&&b<60){
        cout << 0;
    }else if(a<60||b<60){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}

int ch010411(){
    int a;
	cin >> a;
    if(a==1||a==3||a==5)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}

int ch010412(){
    int a;
    cin >> a;
    if(a<100)
        cout << "Walk";
    if(a==100)
        cout << "All";
    if(a>100)
        cout << "Bike";

    return 0;
}

int ch010413(){
    double x;
    cin >> x;
    if(0<=x&&x<5)
        printf("%.3f",-x+2.5);
    if(5<=x&&x<10)
        printf("%.3f",2-1.5*(x-3)*(x-3));
    if(10<=x&&x<20)
        printf("%.3f",x/2-1.5);

    return 0;
}

int ch010414(){
    double x,o=0;
    char a;
    cin >> x >> a;
    o+=8;
    x-=1000;
    for(;x>0;x-=500)
        o+=4;
    if(a=='y')
        o+=5;
    cout << o;

    return 0;
}

int ch010415(){
    int x,y,z,o;
    cin>>x>>y>>z;
    o=x>y?x:y;
    o=o>z?o:z;
    printf("%d",o);

    return 0;
}

int ch010416(){
    int x,y,z;
    cin>>x>>y>>z;
    if(x+y>z&&y+z>x&&z+x>y)
        cout<<"yes";
    else
        cout<<"no";

    return 0;
}

int ch010417(){
    int y;
    cin>>y;
    if(0==y%3200||(0==y%100&&y%400)||(y%4))cout<<"N";
    else cout<<"Y";
    return 0;
}

int ch010418(){
    double x,y;
    cin>>x>>y;
    if(-1<=x&&x<=1&&-1<=y&&y<=1)cout<<"yes";
    else cout<<"no";
    return 0;
}

int ch010419(){
    int a,b;
    char o;
    cin>>a>>b>>o;
    if('+'==o)cout<<a+b;
    else if('-'==o)cout<<a-b;
    else if('*'==o)cout<<a*b;
    else if('/'==o){
        if(0==b)cout<<"Divided by zero!";
        else cout<<a/b;
    }else cout<<"Invalid operator!";
    return 0;
}

int ch010420(){
    double a,b,c,d,m;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    m=-b/(2*a);
    if(d>0){
        double x1=(-b+sqrt(d))/(2*a),x2=(-b-sqrt(d))/(2*a);
        if(!x1)x1=0;
        if(!x2)x2=0;
        printf("x1=%.5f;x2=%.5f",max(x1,x2),min(x1,x2));
    }
    if(0==d){
        if(0==m)printf("x1=x2=0.00000");
        else printf("x1=x2=%.5f",m);
    }
    if(d<0){
        if(0==m)printf("x1=0.00000+%.5fi;x2=0.00000-%.5fi",abs(sqrt(-d)/(2*a)),abs(sqrt(-d)/(2*a)));
        else printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi",m,sqrt(-d)/(2*a),m,sqrt(-d)/(2*a));
    }
    return 0;
}

