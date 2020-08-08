#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double a, double b, double c)
{
    //double pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328;

    //c=c*pi/180.0;
    
    double res = 0;
    res = (2 * a - b - sin(c)) / (5.0 + abs(c));

    return res;
}
int main()
{
    cout << fixed << setprecision(6);
    int n;
    cin >> n;
    double s, t;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> t;
        double res = f(t, 2.0 * s, 1.1700) + f(2.2, t, s - t);
        cout << res << endl;
    }

    return 0;
}