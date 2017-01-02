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
