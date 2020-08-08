#include <bits/stdc++.h>

using namespace std;
double a, b, c, x;
void Gb()
{
    double res = 0.0, h = 0.0;
    res += b + c + sqrt(a * a + c * c);
    x = (x / 100) * (sqrt(a * a + b * b));
    h = b * (sqrt(a * a + b * b) - x) / (sqrt(a * a + b * b));
    h = (b + c - h);
    res += h;
}
int main()
{
    int testcase;
    while (testcase--)
    {
        cin >> a >> b >> c >> x;
        Gb();
    }
}