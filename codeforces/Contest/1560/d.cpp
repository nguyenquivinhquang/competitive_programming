#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int get_min(int x, int y) {
    vector<int> a, b;
    while (x > 0) {
        a.push_back(x % 10); x/=10;
    }
    while (y > 0) {
        b.push_back(y % 10); y/=10;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // make a equal b
    int s_a = 0, s_b = 0;
    int res = 0;
    while(1) {
        if (a[s_a] != b[s_b]) {
            s_a++; res++;
        } else s_b++, s_a++;
        if (s_a == a.size() || s_b == b.size()) break;
    }
    if (s_b < b.size()) res = res + b.size() - s_b;
    if (s_a < a.size()) res += a.size() - s_a;
    return res;
}
void solve() {
    int n; cin >> n; int res = 1e9;
    int po2 = 1;
    while (po2 < 1e18) {
        res = min(res, get_min(n, po2));
        po2 *= 2;
        // if (po2 == 1024) {
        //     cout << "ok";
        // }
    }
    cout << res << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
