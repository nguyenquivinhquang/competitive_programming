#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n + 10], b[m + 10];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int j = 1, res = 0;
    for (int i = 1; i <= m; i++)
    {
        while (j <= n)
        {
            if (b[i] <= a[j] + k && b[i] >= a[j] - k)
            {
                res++;
                j++;
                break;
            }
            if (b[i] < a[j] - k)
                break;
            if (b[i] > a[j] + k)
                j++;
        }
    }
    cout << res;
}