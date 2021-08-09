#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200000;

using namespace std;
vector<int> trace[N];
map<int,int> book, sl;
void solve() {
    int x, l, k, n, m, res = 0;
    set<int> s;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> x >> l >> k;
        book[i] = l;
        int le = max(1, x- k), ri = min(x+k, n)+1;
        trace[le].push_back(i);
        trace[ri].push_back( -i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto v : trace[i]) {
            if (v > 0) {
                s.insert(v);
                sl[book[v]]++;
            } else {
                auto it = s.find(-v);
                if (it == s.end()) continue;
                s.erase(it);
                sl[book[-v]]--;
            }
        }
        if (s.size() == 0) {
            res++;
            continue;
        }
        auto it = s.end(); it--;
        if (sl[book[*it]] > 1) res++;
    }
    cout << res << "\n";
    for (int i = 1; i < N; i++) trace[i].clear();
    book.clear(); sl.clear();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}
