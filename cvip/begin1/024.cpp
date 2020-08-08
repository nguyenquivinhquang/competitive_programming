#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    int t;
    double a;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a;
        if (a > 0)
        {
            double res = 0;
            double n = 0;
            while (res <= a)
            {
                n++;
                res = res + 1 / n;
            }
            cout << n + 1 << endl;
        }
        else
            cout << 2 << endl;
    }
    return 0;
}