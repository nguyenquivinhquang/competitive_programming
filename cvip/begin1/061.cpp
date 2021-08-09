#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const int n = 25;
int main()
{
    cout << fixed << setprecision(5);
    int x;
    int min_average = 10000000;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    int c, b;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (  abs((a[i] + a[j]) / 2 - x) < min_average)
            {
                min_average = abs((a[i] + a[j]) / 2 - x);
                b = a[i];
                c = a[j];
            }

    cout << b << " " << c;
}