#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[N];
void solve() {
    string str; cin >> str;
    int cur = 0, init = 0;
    for (auto v : str) {
        if (v == '<') cur++;
        else cur--;
        if (cur < 0) init++;
    }
    a[0] = init; int m = 1e9;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '<') a[i+1] = a[i] + 1;
        else a[i+1] = a[i] - 1;
        m = min(m, a[i]); 
    }
    long long res = 0;
    for (int i = 0; i <= str.length(); i++) a[i] -= m, res += a[i];
    for (int i = 0; i <= str.length(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
