#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int t;
    int n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        for (int a = 0; a <= n; a++)
        {
            if (((n - 3 * a) % 5 == 0)&&(n-3*a>=0))
                cout << a << " " << (n - 3 * a) / 5<<" ";
        }
        cout << endl;
    }
    //cout<<setprecision(5);
    return 0;
}
