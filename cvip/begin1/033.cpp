#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t, n, a;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        int t = 0;
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if ((a % 5 == 0) && (a % 7 != 0))
            {
                sum += a;
                t++;
            }
            
        }
    cout << t <<" "<<sum<<endl;
    }
}