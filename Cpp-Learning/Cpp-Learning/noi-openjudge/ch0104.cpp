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
