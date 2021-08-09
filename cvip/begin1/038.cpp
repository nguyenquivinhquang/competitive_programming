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
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        bool check = false;
        for (int j = 1; j < sqrt(n); j++)
        {
            if ((n % (j * j) == 0) && (n % (j * j * j) != 0))
            {
                cout << j << " ";
                check = true;
            }
        }
        if(check==false) cout<<"0 ";
        cout<<endl;
    }
    return 0;
}