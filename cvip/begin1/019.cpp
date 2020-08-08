#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    double n, m;
    for (int i = 1; i <= t; i++)
    {
        cin >> m >> n;
        double res = 0;
        double res2 = 0;
        if (m >= 12)
            m = m - 12;
        if (n==60) n=0;
        if (m * 5 < n)
        {
            res = ((m / 6) - (n / 30) + 2) * 360.000 / 11.0000;
        }
        else
        {
            res = (m / 6 - n / 30) * 360.000 / 11.0000;
        }
        
        res2 = ((m / 6) - (n / 30) + 0.5000) * 360.000 / 11.0000; if (res2<0) res2=111111;
        double res3=-1111111;
        double res4=-1111111;
        double res5=res4;
        res3=((m / 6) - (n / 30) + 2.5000) * 360.000 / 11.0000; if (res3<0) res3=111111;
        res4=((m / 6) - (n / 30) + 1.5000) * 360.000 / 11.0000; if (res4<0) res4=111111; 
        res5=((m / 6) - (n / 30) - 0.5000) * 360.000 / 11.0000; if (res5<0) res5=111111;
        res2=min(res2,res3);
        res2=min(res2,res4);
        res2=min(res2,res5);
        
        
        cout << res << " " << res2<<endl;

        //res=(n/15.0000-m/3.0000+1/2)*360.000/11.0000;
        //cout<<res<<endl;
    }
    return 0;
}