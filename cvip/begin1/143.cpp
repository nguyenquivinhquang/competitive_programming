#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<int> scp;
set<int> s;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200 - i * i; j++) {
            for (int x = 1; x <= 200 - i * i - j * j ; x++) {
                for (int y = 1; y <= 200 - i * i - j * j - x * x; y++) {
                    int t = x * x + y * y + i * i + j * j;
                    if (t > 1e4) break;
                    s.insert(t);
                }
            }
        }
    }
    // cout << "ok" << endl;
    for (auto v : s){
        scp.push_back(v);
        // cout << v << endl;
    }
    // cout << scp[scp.size() - 1] << endl;
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        for (auto v : s) {
            if (l <= v && v <= r) {
                cout << v << "\n";
                break;
            }
        }
    }
}
