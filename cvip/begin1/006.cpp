#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n, a, b, c, x, y;
    cin >> n;
    cout<<fixed;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> x >> y;
        cout << setprecision(5) << (a * x + b * y + c) / (sqrt(a * a + b * b)) << endl;
    }
    //cout<<setprecision(5);
    return 0;
}