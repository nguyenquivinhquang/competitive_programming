#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll testcase, n, g, b, res;
    cin >> testcase;
    while (testcase--)
    {

        cin >> n >> g >> b;

        {
            ll n1 = (n + 1) / 2;
            ll x = n1 / g;
            res = x * (g + b);
            if (n1 % g != 0)
                res += n1 % g;
            else
                res -= b;
            cout << max(res, n) << endl;
        }
    }
}