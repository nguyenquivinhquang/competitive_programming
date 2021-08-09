#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n;
    double x;
    cin >> n;
    cout << fixed;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cout<<setprecision(5)<<((2 * pow(x,4)) - (3 *pow(x,3)) + (4 *pow(x,2)) - (5 * x) + 6)<<endl;
    }
    //cout<<setprecision(5);
    return 0;
}

