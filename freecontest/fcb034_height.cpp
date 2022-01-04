#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 400000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], c_l[N], c_r[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> q;
    for (int i = 1;i <= n; i++) {
        while (q.size() && a[q.back()] < a[i]) q.pop_back();
        int debug;
        if (q.size() ) debug = q.back();
        if (q.size() && a[q.back()] == a[i]) c_l[i] = c_l[q.back()] + 1;
        q.push_back(i);
    }
    q.clear();
    reverse(a + 1, a + 1 + n);
    for (int i = 1;i <= n; i++) {
        while (q.size() && a[q.back()] < a[i]) q.pop_back();
        if ( q.size() &&a[q.back()] == a[i]) c_r[i] = c_r[q.back()] + 1;
        q.push_back(i);
    }
    reverse(c_r + 1, c_r + 1 + n);
    for (int i = 1; i <= n; i++) cout << c_r[i] + c_l[i] << " ";
    cout << "\n";
    memset(c_l, 0, sizeof(c_l));
    memset(c_r, 0, sizeof(c_r));
    cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    // freopen("D:\\competitive_programming\\freecontest\\input.txt", "r", stdin);
    // freopen("D:\\competitive_programming\\freecontest\\ouput.txt", "w", stdout);

    int t; cin >>t;
    while(t--) solve();
}
