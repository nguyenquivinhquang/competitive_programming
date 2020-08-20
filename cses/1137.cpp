#include <bits/stdc++.h>
#define N 200005
#define ll long long
#define pp pair<ll, ll>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, v) memset(x, v, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
ll n, value[N], first[N], last[N], a[2 * N + 1000], fen[2*N+1000];
vector<ll> verices[N], EulerTour;
void dfs(ll u, ll preu)
{
    EulerTour.push_back(u);
    for (auto v : verices[u])
    {
        if (v == preu)
            continue;
        dfs(v, u);
        EulerTour.push_back(u);
    }
}
void update(ll p, ll val)
{
    for (ll i = p; i <= EulerTour.size(); i += i & -i)
        fen[i] += val;
}
ll sum(ll p)
{
    ll ans = 0;
    for (ll i = p; i; i -= i & -i)
        ans += fen[i];
    return ans;
}
int main()
{
    reset(first, 0), reset(last, 0), reset(a, 0);
    ll q, x, y, z;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> value[i];
    for (ll i = 1; i < n; i++)
    {
        cin >> x >> y;
        verices[x].push_back(y), verices[y].push_back(x);
    }
    EulerTour.push_back(0);
    dfs(1, 0);
    for (ll i = 1; i < EulerTour.size(); i++)
    {
        if (first[EulerTour[i]] == 0)
        {
            first[EulerTour[i]] = i;
            a[i] = value[EulerTour[i]];
        }
        last[EulerTour[i]] = i;
        update(i, a[i]);
    }

    while (q--)
    {
        cin >> z;
        if (z == 1)
        {
            cin >> x >> y;
            update(first[x], y - a[first[x]]);
            a[first[x]] = y;
        }
        else
        {
            cin >> x;
            cout << sum(last[x]) - sum(first[x] - 1) << endl;
        }
    }
}