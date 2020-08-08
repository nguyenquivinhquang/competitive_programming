#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n;
    double a, b, c;
    cin >> n;
    cout << fixed;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        if (a > 0 && b > 0 && c > 0)
        {
            double p = (a + b + c) / 2;
            double ha = 2 * (sqrt(p * (p - a) * (p - b) * (p - c))) / a;
            double hb = 2 * (sqrt(p * (p - a) * (p - b) * (p - c))) / b;
            double hc = 2 * (sqrt(p * (p - a) * (p - b) * (p - c))) / c;

            double ma = sqrt((b * b + c * c) / 2 - a * a / 4);
            double mb = sqrt((a * a + c * c) / 2 - b * b / 4);
            double mc = sqrt((a * a + b * b) / 2 - c * c / 4);

            double da = 2 / (b + c) * sqrt(b * c * p * (p - a));
            double db = 2 / (a + c) * sqrt(a * c * p * (p - b));
            double dc = 2 / (b + a) * sqrt(b * a * p * (p - c));

            cout << setprecision(5) << ha << " " << hb << " " << hc << " " << ma << " " << mb << " " << mc << " " << da << " " << db << " " << dc << endl;
        } else cout<<"0.00000 "<<endl;
    }

    //cout<<setprecision(5)
    return 0;
}