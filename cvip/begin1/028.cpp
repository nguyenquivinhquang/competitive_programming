#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

vector<bool> mark(100000, true);

int fraction(int a, int b)
{
    int x = a;
    int y = b;
    while (x != y)
    {
        if (x > y)
        {
            x = x - y;
        }
        else
        {
            y = y - x;
        };
    };
    return x;
}
void eratos()
{
    for (int i = 2; i * i <= 100000; i++)
    {
        if (mark[i])
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                mark[j] = false;
            }
        }
    }
}
int main()
{
    cout << fixed << setprecision(5);
    mark[0] = mark[1] = false;
    eratos();
    int t;
    int a, b;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        int ucln = fraction(a, b);
        if (ucln>1){
            cout << a/ucln  << " " << b/ucln ;
        } else
        {
            cout << "NO ANSWER FOR THIS INPUT";
        }
        cout<<endl;
    }
    return 0;
}
