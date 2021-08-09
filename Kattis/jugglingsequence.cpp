#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> xc;

void brute() {
    const int LIM = 150;
    int cur = 1; xc.push_back(cur);
    for (int i = 1; i <= LIM; i++) {
        if (cur <= i) cur += i;
        else cur -= i;

        xc.push_back(cur);
    }
}

#define int long long

int cnt(int n, int md) {
// how many numbers < mid
//cout << "Checking " << md << endl;
    int ans = 0;
    if (md > 1) ans = 1;

    int l = 1, r = 1;
    for (int i = 1; ; i *= 3) {
        l++;
        r = min(n, l+i-1);

        if (l > n) break;
        // << l << ' ' << r << endl;

        int evcnt = (r-l+1)/2;
        int odcnt = (r-l+1) - evcnt;
        //cout << "count: " << evcnt << ' ' << odcnt << endl;
        // odd positions increasing
        // begin with i+1
        int lodd = i+1, rodd = lodd + odcnt - 1;
        if (rodd < md) ans += odcnt;
        else ans += max(0LL, md-lodd);

        // even positions decreasing
        // begin with evcnt, end at 1
        if (evcnt > 0) {
            int lev = i/2, rev = lev - evcnt + 1;
            swap(lev, rev);
            if (rev < md) ans += evcnt;
            else ans += max(0LL, md-lev);

        //cout << "Even: " << lev << ' ' << rev << endl;
        }

        //cout << "Odd: " << lodd << ' ' << rodd << endl;

        l = r;
    }
    //cout << "Answer " << md << ' ' << ans << endl;
    return ans;
}

int brut(int n, int m) {
    vector<int> gg;
    for (int i = 0; i < n; i++) gg.push_back(xc[i]);
    sort(gg.begin(), gg.end());

    return gg[m-1];
}

void solve(int n, int m) {
    int lo = 1, hi = 4e18;

    while (lo < hi) {
        int mid = (lo + hi + 1)/2;
        // how many numbers < mid
        if (cnt(n, mid) >= m) {
            // too high
            hi = mid-1;
        } else {
            lo = mid;
        }
    }

    //cout << n << ' ' << m << endl;
    //assert(lo == brut(n, m));
    cout << lo << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //brute();

//    for (int n = 1; n <= 150; n++) {
//        for (int m = 1; m <= n; m++) {
//            solve(n, m);
//        }
//    }
//    cerr << "All tests passed" << '\n';

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }

    return 0;
}
