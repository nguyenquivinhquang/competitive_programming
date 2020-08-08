#include <bits/stdc++.h>
#define maxn 101
#define ll double
#define pp pair<ll, ll>
using namespace std;

int testcase;

int main()
{
    ll h, c, t;
    cin >> testcase;
    while (testcase--)
    {
        int  x = 2;
        double res = 0.0;
        cin >> h >> c >> t;
        // case 1:
        res = abs((h + c) / 2.0 - t);
        x = 2;
        // case 2;
        if (c + h - 2.0*t != 0)
        {
            int temp = abs((t - h) / (c + h - 2.0 * t));
            if ((abs((temp * (h + c) + h) / (2.0 * temp + 1.0)) - t) < res)
            {
                res = (abs((temp * (h + c) + h) / (2.0 * temp + 1.0) - t));
                x = temp+temp+1;
            }
            temp++;
            if ((abs((temp * (h + c) + h) / (2.0 * temp + 1.0) - t)) < res)
            {
                res = (abs((temp * (h + c) + h) / (2.0 * temp + 1.0) - t));
                x = temp+temp+1;
            }
        }
        cout << x << endl;
    }
}