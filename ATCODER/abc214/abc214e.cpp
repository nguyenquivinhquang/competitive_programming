#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
void solve() {
    int n;
    map<int, vector<int>> trace;
    set<int> setL;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        trace[l].push_back(r);
        setL.insert(l);
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    setL.insert(10000000100);
    int i = *setL.begin();

    while (i <= 1e9) {
        for (auto v : trace[i]) q.push(v);
        q.pop();
        if (q.size()==0) {
            i = *setL.lower_bound(i+1);
            continue;
        }

        if (q.top() <= i) {
            cout << "No\n";
            return;
        }
        i++;
    }
    if (q.size()) {
        cout << "No\n";
    } else cout << "Yes\n";

}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();

}
