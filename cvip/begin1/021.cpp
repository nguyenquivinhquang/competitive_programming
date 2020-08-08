#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int t;
    int n;
    cout << fixed;
    cout << setprecision(5);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        if (n > 0)
        {
            long res = 1;
            long y = 1;
            for (int j = 1; j <= n; j++)
            {
                res = res * j;
                y = 2 * y;
            }
            double x1, x2;
            x1 = 1.00000;
            x2 = 0.00000;
            for (int j = 1; j <= n; j++)
            {
                double k = j * j;
                x1 = x1 * (1 + (1 / k));
                x2 = 2 + sqrt(x2);
            }
            x2 = sqrt(x2);
            cout << y << " " << res << " " << x1 << " " << x2 << endl;
        }
        else
            cout << 0.00000 << endl;
    }
    //cout<<setprecision(5);
    return 0;
}