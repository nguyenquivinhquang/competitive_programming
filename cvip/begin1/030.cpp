#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    double a[10000];
    double b[10000];
    double c[10000];
    a[1] = 1.00000;
    b[1]=a[1];
    c[1] = 1.00000;
    for (int i = 2; i <= 10000; i++)
    {
        a[i] =  (sqrt(b[i - 1]) + 0.5000 * (sqrt(a[i - 1]) )   ); a[i]=a[i]/2;
        b[i]=b[i-1]+a[i-1]*a[i-1]*2.00000;
        c[i]=c[i-1]+a[i]*b[i];
    }
    int t, x;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> x;
        cout << c[x] << endl;
    }
    return 0;
}