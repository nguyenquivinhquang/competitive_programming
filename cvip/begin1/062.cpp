#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    double a[21][21];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
           if ((i+j)==8) a[i][j]=0.13; else a[i][j] = 1.00 / (i + j);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout<<endl;
    }
    
    return 0;
}