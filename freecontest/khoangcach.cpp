#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
double f(int x1, int v1, int x2, int v2, double t)
{
    return abs(x1 + v1 * t - x2 - v2 * t);
}
int min_f(int x1, int v1, int x2, int v2)
{

    int N_ITER = 100;
    double left = -100000000, right = -left;
    for (int i = 0; i < N_ITER; i++)
    {

        double k1 = left + (right - left) / 3.0;
        double k2 = right - (right - left) / 3.0;

        if (f(x1, v1, x2, v2, k1) < f(x1, v1, x2, v2, k2))
            right = k2;
        else
            left = k1;
    }
    return f(x1, v1, x2, v2, left);
}
int main()
{
    fastio;
    int n, x[N], v[N];
    ll res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            res += min_f(x[i], v[i], x[j], v[j]);
    cout << res << endl;
}