#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
long long s;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> s;
	cout << s << ":\n";
    for (int i = 2; i <= (s + 1) / 2; i++) {
        int f = i, se = i - 1;
        if (s % (f + se) == 0 || s % (f + se) == i) cout << f << "," << se << "\n";
        f = i, se = i;
        if (s % (f + se) == 0 || s % (f + se) == i) cout << f << "," << se << "\n";
    }
}
