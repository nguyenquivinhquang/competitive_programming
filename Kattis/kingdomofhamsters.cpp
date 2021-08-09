#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

const double INF = 1e17;

int n;
vector<pair<int, int>> p;

vector<double> dp;
vector<double> nxt;

double dist(int i, int j) {
    int dx = p[i].first - p[j].first;
    int dy = p[i].second - p[j].second;

    return sqrtl(dx*dx + dy*dy);
}

double f(int ind, int k) {
    return dp[ind - 1] + dist(ind-1, k);
}

void store(int ind, double val) {
    nxt[ind] = val;
}

void dncdp(int l, int r, int lo, int hi) {
    if (l >= r) return;
    int mid = (l + r)/2;

    pair<double, int> best = {0, lo};
    for (int k = lo; k <= min(hi, mid); k++) {
        best = max(best, make_pair(f(k, mid), k));
    }
    store(mid, best.first);

    dncdp(l, mid, lo, best.second+1);
    dncdp(mid+1, r, best.second, hi);
}

void solve() {
    // solve for the current thing
    for (int i = 0; i <= n; i++) {
        dp[i] = nxt[i] = -INF;
    }
    dp[0] = 0;
    for (int i = 0; i < 6; i++) {
        dncdp(1, n+1, 1, n+1);
        swap(nxt, dp);
        fill(nxt.begin(), nxt.end(), -INF);

        //for (int j = 0; j <= n; j++) {
        //    cout << dp[j] << '\n';
        //}
        //cout << '\n';
    }

    cout << dp[n];
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(6);

    cin >> n;
    p.resize(n); dp.resize(n+1); nxt.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    //cout << '\n';
    for (int i = 0; i < n; i++) {
        //for (auto [x, y]: p) cout << x << ' ' << y << endl;
        p.push_back(p[0]);
        solve();
        p.pop_back();
        rotate(p.begin(), p.begin()+1, p.end());
    }

    return 0;
}
