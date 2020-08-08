#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    double t;
    int n, m;
    cin >> n>>m;
    double minh, maxc;
    minh = 1000000;
    maxc = 0;
    for (int i = 1; i <= n; i++)
    {
        minh = 1000000;
        for (int j = 1; j <= m; j++)
        {
            cin >> t;
            minh=min(minh,t);

        }
        maxc=max(maxc,minh);
    }
    cout<<maxc;

    return 0;
}