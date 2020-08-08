#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    int n;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        long long res = 1;
        long long sum=0;
        for (int j = 1; j <= n; j++)
        {
            res=1;
            for (int k=j;k<=2*j;k++)
                res = res * k;
            sum=sum+res;
        }
       cout << sum << endl;
    }
    return 0;
}