#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        int sum = 0;
        int x = sum;
        if (a == 0)
        {
            x = 1;
        }
        while (a > 0)
        {
            sum += a % 10;
            a = a / 10;
            x++;
        }
        cout << x << " " << sum << endl;
    };
    //cout<<setprecision(5);
    return 0;
}