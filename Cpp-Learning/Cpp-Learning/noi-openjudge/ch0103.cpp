#include<bits/stdc++.h>

using namespace std;

int ch010301() {
	int a,b;
	cin >> a >> b;
	cout << a+b;

	return 0;
}

int ch010302() {
	int a,b,c;
	cin >> a >> b >> c;
	cout << (a+b)*c;

	return 0;
}

int ch010303() {
	int a,b,c;
	cin >> a >> b >> c;
	cout << (a+b)/c;

	return 0;
}

int ch010304() {
	int a,b;
	cin >> a >> b;
	cout << a/b << " " << a%b;

	return 0;
}

int ch010305() {
	int a,b;
	cin >> a >> b;
	printf("%.9f", double(a)/b);

	return 0;
}

int ch010306() {
	int a,b;
	cin >> a >> b;
	printf("%.3f%%", double(b)*100/a);

	return 0;
}

int ch010307() {
	double a,b,c,d,x;
	cin >> x >> a >> b >> c >> d;
	printf("%.7f", a*x*x*x+b*x*x+c*x+d);

	return 0;
}

int ch010308() {
	double f;
	cin >> f;
	printf("%.5f", 5 * (f-32) / 9);

	return 0;
}

#ifndef pi
#define pi 3.14159
#endif
int ch010309() {
	double r;
	cin >> r;
	printf("%.4f %.4f %.4f", 2*r,2 * pi * r,pi * r * r);

	return 0;
}
#undef pi

int ch010310() {
	float r1,r2,R;
	cin >> r1>>r2;
	R = 1/(1/r1 + 1/r2);
	printf("%.2f", R);

	return 0;
}

int ch010311() {
	double a,b;
	cin >> a >> b;
	int k=(int)(a/b);
	double r=a-k*b;
	printf("%g", r);

	return 0;
}

#ifndef pi
#define pi 3.14
#endif
int ch010312() {
	double a;
	cin >> a;
	printf("%.2f", 4*pi*a*a*a/3);

	return 0;
}
#undef pi

int ch010313() {
    int x, a, b, c;
    cin >> x;
    a=x/100;
    b=x/10-a*10;
    c=x-a*100-b*10;
    cout << c << b << a;

    return 0;
}

#ifndef pi
#define pi 3.14159
#endif
int ch010314()
{
	int h, r, n;
	double v;
	cin >> h >> r;
	v = pi * h * r * r;
	n = 20000 / v + 1;
	cout << n;

	return 0;
}
#undef pi

int ch010315()
{
    int n,x,y,m;
    cin >> n >> x >> y;
    m=n-y/x;
    if(y%x) {
        m--;
    }
    cout << m;

    return 0;
}

int ch010316()
{
    float xa,ya,xb,yb;
    cin >> xa >> ya >> xb >> yb;
    printf("%.3f",sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));

    return 0;
}

int ch010317()
{
    float x1,y1,x2,y2,x3,y3,p,l1,l2,l3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    l1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    l2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    l3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    p=(l1+l2+l3)/2;
    printf("%.2f",sqrt(p*(p-l1)*(p-l2)*(p-l3)));

    return 0;
}

int ch010318()
{
    float a1,a2,n;
    cin >> a1 >> a2 >> n;
    printf("%g",a1+(a2-a1)*(n-1));

    return 0;
}

int ch010319()
{
    unsigned long a,b;
    cin >> a >> b;
    cout << a*b;

    return 0;
}

int ch010320()
{
    int a;
    unsigned long b=2;
    cin >> a;
    for(int i=0;i<a-1;i++){
        b=b*2;
    }
    if(a==0)
        b=1;
    cout << b;

    return 0;
}
