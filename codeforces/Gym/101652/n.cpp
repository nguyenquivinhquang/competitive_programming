#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
string a;
int n;
bool isPalin(int i, int j) {
    while (i <= j) {
        if (i == j) break;
        if (a[i] != a[j]) return false;
        i++; j --;
    }
    return true;
}
void solve() {
    cin >> a;
    n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (isPalin(j, i) == false) continue;
            int len = i - j + 1;
//            if (len == 1) continue;
            if (len % 2 == 0) {
//                cerr << j << " " << i;
                cout << "Or not.";
                return;
            }
        }
    }
    cout << "Odd.";
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    solve();
}
