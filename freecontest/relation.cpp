#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int main()
{
    int n, k;
    ll res = 0;
    map<int, int> trace, bigger;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
            trace[i % k]++;
        else
            bigger[i % k]++;
    }
    res = trace[0] * trace[0] * trace[0];
    for (int i = 1; i < k; i++)
    {
        int a = i, b = k - i, c;
        res += trace[i] * bigger[i] * bigger[b];
        if (a == b)
        {
            res += trace[i] * trace[i] * trace[i];
        }
    }
    cout << res;
}