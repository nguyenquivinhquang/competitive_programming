#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 300000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k;
int a[N], b[N];
set<pair<int, pii>> q;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        q.insert({a[1] + b[i], {1, i}});
    }
    for (int i = 1; i <= k; i++) {
        int sum = q.begin()->first, x = q.begin()->second.first, y = q.begin()->second.second;
        q.erase(q.begin());
        cout << sum << " ";
        if (x + 1 <= n) q.insert({a[x + 1 ] + b[y], {x + 1, y}});
    }
}
