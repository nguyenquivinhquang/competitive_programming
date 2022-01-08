#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define int long long
ll n;
ll check(ll x){
    return x * (n-1 + n-x) / 2;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    cin >> n;
    int l = 1, r = n;
    ll mid  = ((n * (n-1)) / 2 + 1) / 2;
    while (l < r) {
        ll m = (l + r) / 2;
        if (check(m) < mid) l = m + 1;
        else r   = m;
    }
    cout << l;
}
