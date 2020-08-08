#include <iostream>
#define y "yes"
#define no "no"
using namespace std;
bool check_nguyen(double x)
{
    if (x < 0)
        return false;
    int t = x;
    if (x - t > 0)
        return false;
    return true;
}
int main()
{
    double n, a, c, b, testcase;
    cin >> testcase;
    while (testcase--)
    {
        cin >> a >> b >> c >> n;
        double A, B, C;
        A = (b + c - 2 * a + n) / 3;
        if (check_nguyen(A) == false)
            cout << no;
        else if (A + a - b < 0)
            cout << no;
        else if (A + a - c < 0)
            cout << no;
        else
            cout << y;
        cout << endl;
    }
}