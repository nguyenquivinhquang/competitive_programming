#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double gt(int n)
{
    if (n > 1)
        return n * gt(n - 1);
    else
        return 1;
}
int main()
{
    cout << fixed << setprecision(9);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        double n,m;
        cin>>n>>m;
        cout<< (gt(n)+gt(m))/gt(n+m)<<endl;

    }

    return 0;
}