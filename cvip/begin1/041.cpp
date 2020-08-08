#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(1);
    int t;
    int n;
    cin >> t;
    double minx = 100000000;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        double x;
        cin >> minx;
        for (int j = 2; j <= n; j++)
        {
            cin >> x;
            if (x > minx)
            {
                int temp=x;
                if (temp-x<0)
                cout <<setprecision(1)<< x << " ";else cout <<setprecision(0)<< x << " ";
            }
            else
                minx = x;
        }
        cout << endl;
    }
    return 0;
}