#include <bits/stdc++.h>
#define maxn 200008
#define ll long long
using namespace std;
int main()
{
    ll a[maxn], n, res = 0;
    cin >> n;
    a[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i != 1 && a[i] <= a[i - 1])
            res += a[i - 1] - a[i], a[i] = a[i - 1];
    }
    cout << res;
    vector<int> x, y(10);
    x = y;
}
