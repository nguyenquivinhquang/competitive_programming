#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;
int mu(int x)
{
    int a = 1;
    for (int i= 1; i <= x-1; i++)
    {
        a = a * 10;
    }
    return a;
}
int main()
{
    int t;
    long long n;
    cin >> t;
    cout << fixed << setprecision(5);
    for (int i = 1; i <= t; i++)
    {
       
        cin >> n;

        long long j, res;
        j = 1;
        res = 0;
        int th1 = 0; long long temp=n;
        bool check = false;
        if (n != 0)
        {
            while (n > 0)
            {
                j++;
                res = n % 10;   
                th1 = th1 * 10 + res;
                n = n / 10;
            }
            n=temp*temp;
            while (n>0){
                  res = n % 10;
                if (res == 3)  check = true;
                 n = n / 10;
            }

        }
        else
            j = 2; 
        n=temp;
        j--;
        int x = n / mu(j);
        int y = n % 10;

        n = n % mu(j);
        n = y * mu(j) + n;
        n=n/10;
        n=n*10+x;
        if (check==true) cout <<"true " ; else cout<<"false ";
        cout << th1 <<" "<<n <<endl;
    }
    return 0;
}