#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
ll check1(ll x, ll y, ll n)
{
    ll t = y - 1;
    if (x + t <= n)
        return ((x + t) % 2);
    t = n - x;
    return (y + y + 1) % 2;
}
int main()
{
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    // check 1
    if (check1(x1, y1, n) == check1(x2, y2, n))
        cout << "yes";
    else
        cout << "no";
}