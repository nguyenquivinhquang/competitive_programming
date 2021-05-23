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

const ll INF = 1E10;

ll n, T, s, ntest;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("t.inp", "r", stdin);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        ll res = -INF;
        for (int i = 0 ; i < n ; i++) {
            ll f, t;
            cin >> f >> t;
            ll tmp;
            if (t > s) {
                tmp = f - (t-s);
            } else {
                tmp = f;
            }
            res = max(res, tmp);
        }
        cout << "Case #" << ++ntest << ": " << res << "\n";
    }
    return 0;
}
