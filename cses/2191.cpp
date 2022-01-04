#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    vector<pii> a;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    a.push_back(a[0]);
    ll area = 0;
    for (int i = 1; i <= n; i++) {
        area += (a[i].first + a[i-1].first) * (a[i].second - a[i-1].second);
    }
    cout << (ll) abs(area);
}
