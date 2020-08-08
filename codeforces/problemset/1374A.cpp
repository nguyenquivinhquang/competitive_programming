#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long x, y, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y >> n;
        cout << ((n - y) / x) * x + y << endl;
    }
}
