#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    int n;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        double x, y;
        double res = 1.00000;
        double k = 0.00000;
        double j = 0.00000;
        
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                res = res*(i) / (i + 1.0);
            }
            else
            {
                res = res*(i + 1.0) /    (i);
            }
            
        }
        cout << res << endl;

        
    }
    return 0;
}