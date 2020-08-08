#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int t;
    int n;
    cin >> t;
    cout << fixed << setprecision(5);
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        int j, res;
        j = 1;
        res = 0;
        if (n != 0)
        {
            while (n > 0)
            {
                j++;
                res += n % 10;
                n = n / 10;
            }
        }
        else
            j = 2;
        cout << j - 1 << " " << res << endl;
    }
    return 0;
}