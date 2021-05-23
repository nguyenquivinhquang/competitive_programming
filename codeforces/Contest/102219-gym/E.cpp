#include <bits/stdc++.h>
#define fi first
#define se second
#define max3(a, b, c) max(a, max(b, c))
#define writef(a, n) cout << fixed << setprecision(n) << a


using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll n, t, dp[55][50000], trace[55][50000], a[55], sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("t.inp", "r", stdin);
    while (cin >> t) {
        if (t == 0) return 0;
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
            sum += a[i];
        }
        memset(dp, -1, sizeof dp);
        for (int i = 0 ; i <= n ; i++) {
            dp[i][0] = 0;
        }
        ///dp[i][j] == -1 la chua xac dinh
        for (int i = n-1 ; i >= 0 ; i--) {
            for (int j = 0 ; j <= sum ; j++) {
                ///lay i
                if (j-a[i] >= 0)
                    if ((dp[i+1][j-a[i]] != -1) && (dp[i][j] == -1)) {
                        dp[i][j] = dp[i+1][j-a[i]]+1;
                        trace[i][j] = i;
                    }
                ///khong lay i
                if ((dp[i+1][j] != -1) && (dp[i][j] == -1)) {
                    dp[i][j] = dp[i+1][j];
                    trace[i][j] = trace[i+1][j];
                }
            }
        }
        ll v = a[0], u = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j <= t ; j++) {
                if (dp[i][j] > 0 && trace[i][j] == i) {
                    if (abs(j-t) < abs(v-t)) {
                        u = i;
                        v = j;
                    }
                }
            }
        }
        ll tmp = 0;
        while (v > 0) {
            cout << a[trace[u][v]] << " ";
            tmp += a[trace[u][v]];
            v -= a[trace[u][v]];
            u = trace[u+1][v];
        }
        cout << tmp;
        cout << "\n";
    }
    return 0;
}
