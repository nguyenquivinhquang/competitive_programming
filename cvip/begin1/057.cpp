#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(6);
    double a1, a2;
    a1 = 0;
    a2 = 0;
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 50; j++)
            a1 += 1.0 / (i + j * j);

     for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= i; j++)
            a2 += 1.0 / (i + j + j);
    cout << a1<<endl;
    cout<< a2;

    return 0;
}