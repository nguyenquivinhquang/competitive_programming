#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    int n;
    double temp;
    double s = 0;
    double r = s;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        r = 0;
        s = 0;
        cin >> n;
        for(int j = 1; j <= n; j++)
        {
            cin >> temp;
            if (temp <= 1.00)
                r+=temp;
            else
                s+=temp;
        }
        cout<<(1+r)/(1+s)<<endl;
    }
    return 0;
}