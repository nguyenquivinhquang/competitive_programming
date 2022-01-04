#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 300000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[N], n;
void solve() {
    vector<int> b, r;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == 'B') {
            if (a[i] <= 0) continue;
            b.push_back(a[i]);
        } else {
            r.push_back(a[i]);
        }
    }
    sort(r.begin(), r.end());
    sort(b.begin(), b.end()); 
    queue<int> qb, qr;
    for (auto v :b) qb.push(v);
    for (auto v : r) qr.push(v);
    bool check = true;
    for (int i = 1; i <= n; i++) {
        if (qb.size()) {
            if (qb.front() >= i) {
                qb.pop();
                continue;
            }
        }
        if (qr.size()) {
            if (qr.front() <= i) {
                qr.pop();
                continue;
            }
            
        }
        check= false;
        break;
    }   
    if (check) cout << "YES\n";
    else cout << "NO\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
