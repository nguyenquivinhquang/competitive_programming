#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double gt(double x)
{
    double i = 0;
    double temp = 1;
    while (i < x)
    {
        i++;
        temp *= i;
    }
    return temp;
}
double power(double x, double b)
{
    double temp = 1;
    for (int i = 1; i <= b; i++)
    {
        temp = temp * x;
    }
    return temp;
}
int main()
{
    cout << fixed << setprecision(6);
    double n, x;
    cin >> n >> x;
    double a1 = 0;
    for (int k = 1; k <= n; k++)
    {
        double a2=0;
        a2 += power(-1, k) * power(x, k);
        a2 = a2 / gt(gt(k) + 1);
        a1+=a2;
    }
    double a2=0;
    for (int k=1;k<=n;k++)
        for (int m=k;m<=n;m++){
            a2=a2+(x+k)/m; 
        }

    a1 = (1 / gt(n)) * a1;
    cout << a1<<endl;
    cout<<a2;
    return 0;
}