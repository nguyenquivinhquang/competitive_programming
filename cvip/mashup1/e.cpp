#include <bits/stdc++.h>

using namespace std;
double mu(double x, double y)
{
    return x * x;
}
int main()
{
    double r, x1, x2, y1, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double distance = sqrt(mu(x1 - x2, 2) + mu(y1 - y2, 2)) / (2.0 * r);
    cout << ceil(distance);
}