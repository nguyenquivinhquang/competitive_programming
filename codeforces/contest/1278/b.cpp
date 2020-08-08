#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll sum(int x)
{
    double res = 0;
    for (int i = 1; i <= x; i++)
    {
        res += i;
    }
    return res;
}
bool check_nguyen(double a)
{
    if (a < 0)
        return false;
    ll x = a;
    if (a - x > 0)
        return false;
    else
        return true;
}
int Hoai_Thuong(double a, double b)
{
    double x = 1.1, y = 1.1;
    double s;
    int i = -1;
    if (a < b)
        swap(a, b);
    a = a - b;
     b=0;
    while ((check_nguyen(x) != true) || (check_nguyen(y) != true))
    {
        i++;
        b = b+i;
        x = (a + b) / 2.0;
        y = b - x;
    }
    return i;
}
int main()
{
    int t, a, b;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cout << Hoai_Thuong(a, b) << endl;
    }
    //cout<<sum(100000);
}