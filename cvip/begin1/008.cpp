#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << fixed;
    double a, b, alpha, s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> alpha;
        s = (((b - a) * tan(alpha) * (a + b)) / 4);
        if (s < 0)
            s = s * -1;
        cout << setprecision(5) << s << endl;
    }

    //cout<<setprecision(5);
    return 0;
}