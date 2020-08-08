#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int x[5];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char a, b, c, d;
        cin >> a >> b >> c >> d;
        x[1] = a - 48;
        x[2] = b - 48;
        x[3] = c - 48;
        x[4] = d - 48;
        x[0] = -111;
        if ((a == d) && (b == c))
        {
            cout << "co" << endl;
        }
        else
        {
            sort(x, x + 5);
            cout << "ko ";
            int temp = 1;
            bool check = false;
            bool check2=true;
            for (int j = 2; j <= 4; j++)
            {
                if (x[j] == x[j - 1])
                    temp++;
                else
                {
                    if (temp==2) check2=false;
                    if (temp >= 3)
                        check = true;
                    temp = 1;
                }
            }
            if (x[1] == x[4])
                temp++;
            if (check==true)
            {
                cout << "3";
            } else
            if (check2==true)
                cout << "4";
            cout << endl;
        };
    }
    //cout<<setprecision(5);
    return 0;
}