#include<bits/stdc++.h>

using namespace std;

int ch010201() {
	short a;
	int b;
	printf("%d %d", sizeof(b), sizeof(a));
	return 0;
}

int ch010202() {
	double a;
	float b;
	printf("%d %d", sizeof(b), sizeof(a));
	return 0;
}

int ch010203() {
	char a;
	bool b;
	printf("%d %d", sizeof(b), sizeof(a));
	return 0;
}

int ch010204() {
    printf("D C");

	return 0;
}

int ch010205() {
    printf("F E");

	return 0;
}

int ch010206() {
    float a;
    cin >> a;
    cout << (int) a;

	return 0;
}

int ch010207() {
	char a;
	cin >> a;
	cout << (int) a;

	return 0;
}

int ch010208() {
	int a;
	cin >> a;
	cout << (char) a;

	return 0;
}

int ch010209() {
	int a,c;
	bool b;
	cin >> a;
	b=(bool) a;
	c=(int) b;
	cout << c;

	return 0;
}

int ch010210() {

	cout << sizeof("Hello, World!");

	return 0;
}
