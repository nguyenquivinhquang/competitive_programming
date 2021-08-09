#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int cal(string x)
{
    long long a[20];
    memset(a, 0, sizeof(a));
    int count = 1;
    int m = 1;
    for (int i = 0; i < x.length(); i++)
    {

        if (count % 10 == 0)
        {
            m++;
            count = 1;
        }
        a[m] = a[m] * 10 + (int(x[i]) - 48);
        count++;
    }
    long long sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum = (sum % 9 + a[i] % 9) % 9;
    }
    return sum;
}
int main()
{
    long long n;
    string k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        cout << cal(k) << endl;
    }

    return 0;
}