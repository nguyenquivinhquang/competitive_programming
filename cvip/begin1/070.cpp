#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double g(double a, double b)
{
    double res = 0;
    res = (a * a + b * b) / (a * a + 2 * a * b + 3 * b * b + 4);
    return res;
}
int main()
{
    cout << fixed << setprecision(6);
    int t;
    cin >> t;
    double a,b;
    for (int i = 1; i <= t; i++)
    {
        cin>>a>>b;
        double res=g(1.2,a)+g(b,a)-g(2*a-b,a*b);
        cout<<res<<endl;
    }

    return 0;
}