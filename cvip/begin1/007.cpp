#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const double pi=3.14159;
int main()
{
    int n;
    double d;
    cin>>n;
    cout<<fixed;
    for (int i = 1; i <= n; i++)
    {
        cin >> d;
        cout<<setprecision(5)<<d*d/(4*pi)<<endl;

    }
    //cout<<setprecision(5);
    return 0;
}