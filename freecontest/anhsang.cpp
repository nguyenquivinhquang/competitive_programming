#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<double, double>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int main()
{
    pp cor[N];
    double temp, res = 0.0;
    int n;
    cin >> temp >> temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cor[i].first >> cor[i].second;
    }
    cor[0] = cor[n], cor[n + 1] = cor[1];
    for (int i = 1; i <= n; i++)
    {
        res += (cor[i + 1].first + cor[i].first) * (cor[i + 1].second - cor[i].second);
    }
    res /= 2.0;
    if (res < 0)
        res *= -1.0;
    printf("%.2f", res);
}