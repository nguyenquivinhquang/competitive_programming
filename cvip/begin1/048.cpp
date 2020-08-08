#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int a[100000];
    a[1] = 1;
    int max_res = 0;
    int res = 0;

    for (int i = 1; i <= 10000; i++)
    {
        a[i] = i;
        for (int j = i / 2; j >= 1; j--)
        if (i%j==0)
        {
            a[i] += j;
        }
        if (max_res < a[i])
        {
            res = i;
            max_res = a[i];
        }
    }
    cout << res;

    return 0;
}