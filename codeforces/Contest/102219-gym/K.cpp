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

ll n, a[100005], ntest, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("t.inp", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        ll cur = 0, res = 0;
        for (int i = 0 ; i < n ; i++) {
            if (cur + a[i] <= a[i]*2) {
                res++;
                cur += a[i];
            }
        }
        cout << "Case " << "#" << ++ntest << ": " << res << "\n";
    }
    return 0;
}
