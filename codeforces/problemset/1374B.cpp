#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        ll n, step = 0;
        cin >> n;
        while (n > 1)
        {
            if (n % 6 == 0)
                n /= 6, step++;
            else if (n % 3 == 0)
                step += 2, n /= 3;
            else
                break;
        }
        if (n > 1)
            cout << -1;
        else
            cout << step;
        cout << endl;
    }
}