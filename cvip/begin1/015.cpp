#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n;
    double x, y;
    cin >> n;
    cout << fixed;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        cout << setprecision(5) << ((3 * x * x * y * y) - (2 * x * y * y) - (7 * x * x * y) - (4 * y * y) + (15 * x * y) + (2 * x * x) - (3 * x) + (10 * y) + 6) << endl;
    }
    //cout<<setprecision(5);
    return 0;
}
