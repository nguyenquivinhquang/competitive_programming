#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    double a, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        cin >> a >> n;
        if ((a !=0) && (n != 0))
        {
            double x1 = 1;
            double x2 = a*a;
            double x3 = 1 / a;
            double mul = a;
            for (int j = 1; j <= n; j++)
            {
                x1 = x1 * a;
                x2 = x2 * (a + j);
                mul = mul * (a + j);
                x3 = x3 + 1 / mul;
            }
            x2 = x2 / (n + a);
            cout << x1 << " " << x2 << " " << x3 << endl;
        } else cout<<0.00000<<endl;
    } 
    return 0;
}