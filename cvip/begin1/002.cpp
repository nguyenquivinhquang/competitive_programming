#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    double pi = 3.14159;
    double l, g;
    double x;
    g = 918.00000;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        cout << fixed;
        x=2.00000 * pi * sqrt(l / g);
        cout << setprecision(5) << x << endl;
    }

    return 0;
}