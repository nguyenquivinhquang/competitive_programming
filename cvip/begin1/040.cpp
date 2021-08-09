#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    int n;
    for (int i = 1; i <= t; i++)
    {
        int maxt = -10000000;
        int mint = -maxt;
        int x;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            maxt = max(maxt, x);
            mint = min(mint, x);
        }
        cout << mint << " " <<maxt << endl;
    }
    return 0;
}