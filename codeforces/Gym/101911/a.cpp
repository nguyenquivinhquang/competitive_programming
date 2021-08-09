#include <bits/stdc++.h>
#define N 200005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;

int n, m, d, a[N], val[N], total = 0, res[N];
set<pp> query;
map<int, int> pos;

int main()
{
    reset(val, 0);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        query.insert({a[i], i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (val[i] == 0)
            val[i] = ++total;
        auto it = query.upper_bound({a[i] + d, n + 1});
        if (it != query.end())
        {
            val[it->second] = val[i];
            query.erase(it);
        }
        res[pos[a[i]]] = val[i];
    }
    cout << total << endl;
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}