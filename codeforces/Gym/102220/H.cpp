#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

#define int long long

struct segtree{
    int n;
    vector<int> a, it;

    segtree(int n) {
        this->n = n;
        a.resize(n+1, 0);
        it.resize(4*n + 6, 0);
    }
    void update(int node, int l, int r, int pos, int val)
    {
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            it[node] = val;
            //cout << l << ' ' << r << '\t' << it[node] << '\n';
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, pos, val);
        update(node * 2 + 1, mid + 1, r, pos, val);
        it[node] = it[node * 2 + 1] + it[node * 2];
        //cout << l << ' ' << r << '\t' << it[node] << '\n';
    }
    ll get(int node, int l, int r, int u, int v)
    {
        if (r < u || l > v)
            return 0;
        if (u <= l && r <= v)
            return it[node];
        int mid = (l + r) / 2;
        return get(node * 2, l, mid, u, v) + get(node * 2 + 1, mid + 1, r, u, v);
    }
    ll get(int l, int r) {
        return get(1, 1, n, l, r);
    }
    ll get(int p) {
        return get(1, 1, n, 1, p);   
    }
    void add(int pos, int k)
    {
        a[pos] += k;
        //cout << "At " << pos << '\t' << a[pos] << '\n';
        update(1, 1, n, pos, a[pos]);
    }
    void set(int pos, int k)
    {
        a[pos] = k;
        update(1, 1, n, pos, a[pos]);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    segtree s1(n+2), s2(n+2);
    vector<int> a(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        s1.add(i, a[i]);
        s1.add(i+1, -a[i]);

        if (i < n) {
            s2.add(i, max(0LL, a[i+1] - a[i]));
        }
    }

    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int l, r, k; cin >> l >> r >> k;

            // change s2[l-1] and s2[r] if exist
            s1.add(l, k);
            s1.add(r+1, -k);

            // update s2[l-1]
            if (l > 1) {
                s2.set(l-1, max(0LL, s1.get(l) - s1.get(l-1)));
            }
            // update s2[r]
            if (r < n) {
                s2.set(r, max(0LL, s1.get(r+1) - s1.get(r)));
            }
        } else {
            int l, r; cin >> l >> r;
            ll ans = s1.get(l);
            // l to r-1
            if (l < r) {
                ans += s2.get(l, r-1);
            }
            cout << ans << '\n';
        }
    }
}

signed main()
{
    fastio;
    int testcase; cin >> testcase;
    while (testcase--) {
        solve();
    }
}