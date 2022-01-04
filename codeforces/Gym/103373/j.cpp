#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int convert(string a) {
    int res = 0;
    for (auto v : a) {
        if (v < 48 || v > 57) return -1;
        res = res * 10 + (v - '0');
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string a, b; cin >> a >> b;
    int x = convert(a), y = convert(b);
    if (x == -1 || y == -1) cout << "NaN";
    else cout << x - y;
}
