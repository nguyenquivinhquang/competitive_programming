#include <iostream>
#include <cmath>

using namespace std;
long long gt(int x)
{
    long long t = 1;
    for (int i = 1; i <= x; i++)
        t *= i;
    return t;
}
int main()
{
    int n;
    cin >> n;
    if (n < 3)
        {cout << "No"; return 0;};
    int res = pow(gt(n), 1.0 / 3.0);
    long long z = (gt(n));
    for (int i = 3; i <= res + 2; i++)
        if ((i - 1) * (i - 2) * i == z)
        {
            cout << "Yes";
            return 0;

        }
    cout<<"No";
}