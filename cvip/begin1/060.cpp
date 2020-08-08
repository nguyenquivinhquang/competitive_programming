#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const int n = 20;
int main()
{
    cout << fixed << setprecision(5);
    int m;
    int a[21];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                if (a[i] + a[j] + a[k] == m)
                {
                    cout<<i<<" "<<j<<" "<<k;
                    return 0;
                }
                    
            }
    }
    cout <<-1;
}