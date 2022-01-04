#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int to_n(char x) {
    return x - '0';
}
void solve() {
    string str; cin >> str;
    if (to_n(str[str.length() - 1]) % 2 == 0) cout << 0;
    else if (to_n(str[0]) % 2 == 0) cout << 1;
    else {
        bool check = false;
        for (auto v : str) if (to_n(v) % 2 == 0) check = true;
        if (check) cout << 2;
        else cout << -1;
    }
    cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
