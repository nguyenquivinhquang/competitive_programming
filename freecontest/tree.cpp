#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
ll check(ll x, ll y)
{
    map<ll, int> a, b;
    ll step = 0, res = 1e18;
    while (x >= 1)
    {
        a[x] = step++;
        x /= 2;
    }
    step = 0;
    while (y >= 1)
    {
        b[y] = step++;
        if (a.find(y) != a.end())
            return a[y] +   b[y]; 
        y /= 2;
    }
}
int main()
{
    ll x, y, n;
    cin >> n >> x >> y;
    cout << check(x, y);
}