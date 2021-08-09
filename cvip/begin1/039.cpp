#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    double x, y;

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> x >> y;
        int k=1;
        while (pow(y,k)<x)
        {
            k++;
        }
        if (x>=pow(y,k-1))
        cout<<k<<endl; else cout<<0<<endl;
        
    }
    return 0;
}