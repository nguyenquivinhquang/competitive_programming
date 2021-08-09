#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    string a;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a;
        string temp = "";
        for (int j = 0; j < a.length(); j++)
            if ((a[j] != '0') && (a[j] != '5'))
                temp = temp  +a[j];
        cout << temp << endl;
    }
    return 0;
}