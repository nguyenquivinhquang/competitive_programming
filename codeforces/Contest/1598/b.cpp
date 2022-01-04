#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 10000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N][100];
vector<int> b[10];

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) b[j].push_back(i);
        }
    }
    bool check = true;
    for (int i = 1; i <= 5; i++) {
        if (b[i].size() < n/2) continue;
        for (int j = i; j <= 5; j++) {
            if (i == j) continue;
            if (b[j].size() < n/2) continue;
            vector<int> x,y, c;
            map<int,int> trace;
            for (auto v: b[i]) trace[v] = 1;
            for (auto v: b[j]) {
                if (trace[v] != 0) trace[v] = 3;
                else trace[v] = 2;
            }
            for (auto v: trace) {
                if (v.second == 1) x.push_back(v.first);
                else if (v.second == 2) y.push_back(v.first);
                else c.push_back(v.first);
            }
            for (auto v : c) {
                if (x.size() < y.size()) x.push_back(v);
                else y.push_back(v);
            }
            if (x.size() >= n/2 && y.size() >= n/2) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        for (int i = 1; i <= 8; i++) b[i].clear();

        solve();
    }
}
