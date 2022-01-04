    #include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
char a[N], b[N];

void solve() {

    cin >> n;
    for (int i =1 ; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
    bool check = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '1'&& b[i] == '1') check = false;
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
