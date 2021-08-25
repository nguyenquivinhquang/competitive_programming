#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000000;
int num[N], total = 0;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int testcase;
    for (int i = 1; i <= N - 1; i++) {
        if (i % 3 == 0 || i % 10 ==3 ) continue;
        num[++total] = i;
    }
    cin >> testcase;
    while (testcase--) {
        int n; cin >> n;
        cout << num[n] << "\n";
    }
}
