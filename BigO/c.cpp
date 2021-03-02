#include <bits/stdc++.h>
#define fi first
#define se second
#define max3(a, b, c) max(a, max(b, c))
#define writef(a, n) cout << fixed << setprecision(n) << a

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll it[35][400008], n, q;

void update(ll pos, ll bitPos, bool bitVal, ll l, ll r, ll id) {
    if (l > pos || r < pos) return;
    if (l == r) {
        it[bitPos][id] = bitVal;
        return;
    }
    ll mid = l + r >> 1;
    update(pos, bitPos, bitVal, l, mid, id * 2);
    update(pos, bitPos, bitVal, mid + 1, r, id * 2 + 1);
    it[bitPos][id] = it[bitPos][id * 2] + it[bitPos][id * 2 + 1];
}

ll get(ll bitPos, ll i, ll j, ll l, ll r, ll id) {
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) return it[bitPos][id];
    ll mid = l + r >> 1;
    return get(bitPos, i, j, l, mid, id * 2) + get(bitPos, i, j, mid + 1, r, id * 2 + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("t.inp", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        for (int j = 0; j < 31; j++) {
            update(i, j, (a >> j) & 1, 0, n - 1, 1);
        }
    }
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            for (int j = 0; j < 31; j++) {
                update(x - 1, j, (y >> j) & 1ll, 0, n - 1, 1);
            }
        }
        if (type == 2) {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll len = r - l + 1;
            ll res = 0;
            for (ll j = 0; j < 31; j++) {
                ll ones = get(j, l, r, 0, n - 1, 1);
                ll zeros = len - ones;
                if (ones < zeros) {
                    res += (1ll << j);
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}
