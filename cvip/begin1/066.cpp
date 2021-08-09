#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int a[1000][1000];
    int t;
    cin >> t;
    int n, x, y;
    for (int f = 1; f <= t; f++)
    {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        
        for (int i = 1; i <= n; i++)
            if (i != y)
            for (int j = 1; j <= n; j++)
                    if (x != j)
                        cout << a[i][j]<<" ";
        cout<<endl;        
    }

    return 0;
}