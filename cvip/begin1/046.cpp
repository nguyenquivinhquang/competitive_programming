#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(3);
    int t;
    cin >> t;
    int n;
    for (int k = 1; k <= t; k++)
    {
        cin >> n;
        double res = 0; double temp=0;
        for (int i = 1; i <= n; i++)
        {

            
            for (int j = 1; j <= i + 1; j++)
                res += (1.0 / (i * i + j));
            cout << res-temp << " ";
            temp=res;
        }
        cout<<endl;
    }

    return 0;
}