//CMN
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
using namespace std;
ll n, k, lim = -1, c = 0, x = 0;
int main()
{
    cin >> n >> k;
    if (k > ((n * (n - 1)) / 2))
    {
        cout << "Impossible\n";
        return 0;
    }
    ll tich = 0;
    while (tich < k)
    {
        lim++;
        tich+=lim;
        x++;
    }
    x--;
    tich -= lim;

    if (k == 0)
        lim = 0, tich = 0;
    int rem = k - tich;
    for (int i = 1; i <= rem; i++)
        cout << "(";
    if (rem != 0)
    {
        cout << "()";
       
    }
    for (int i = rem + 1; i <= x; i++)
    {
        cout << "(";
    }
    for (int i = 1; i <= x; i++)
        cout << ")";
    for (int i = (2 * x + 1 * 2) + 2; i <= 2 * n; i += 2)
    {
        cout << "()";
    }
}
