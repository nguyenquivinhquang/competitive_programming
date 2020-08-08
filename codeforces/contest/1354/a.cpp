#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, d, q, t;
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c >> d;
        if (b >= a)
            cout << b;
        else if (c <= d)
            cout << -1;
        else
        {
            t = ceil((a - b) * 1.0 / (c - d) * 1.0);

            cout << b + t * c;
        }
        cout << endl;
    }
}