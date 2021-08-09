#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int t;
    int n,m;
    cin >> t;
    cout << fixed << setprecision(5);
    for (int i = 1; i <= t; i++)
    {
        cin >>m>>n;
        int j, res;
        j = 0;
        res = 0;
        if (n != 0)
        {
            while (m>j)
            {
                j++;
                res += n % 10;
                n = n / 10;
            }
        }
        else
            j = 2;
        cout << res << endl;
    }
    return 0;
}