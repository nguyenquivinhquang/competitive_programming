#include <bits/stdc++.h>

using namespace std;
int sum_digit(int t)
{
    int a = 1;
    while (a <= t)
        a = a * 10;
    a = a / 10;
    int sum = 0;
    for (int i = 0; i <= t; i++)
    {
        int x = i;
        while (x >= 1)
        {
            sum += x % 10;
            x = x / 10;
        }
    }
    return sum;
}
int main()
{
    cout << sum_digit(1233);
}