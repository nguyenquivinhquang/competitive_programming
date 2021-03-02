#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;
const int INF = -(int)1e9;
using namespace std;

 
ll it[35][400008], n, q;
 
void update(ll pos, ll POS, bool Val, ll l, ll r, ll id) {
    if (l > pos || r < pos) return;
    if (l == r) {
        it[POS][id] = Val;
        return;
    }
    ll mid = (l + r) / 2;
    update(pos, POS, Val, l, mid, id*2);
    update(pos, POS, Val, mid+1, r, id*2+1);
    it[POS][id] = it[POS][id*2]+it[POS][id*2+1];
}
 
ll get(ll POS, ll i, ll j, ll l, ll r, ll id) {
    if (l > j || r < i) 
        return 0;
    if (l >= i && r <= j) return it[POS][id];
    ll mid = (l + r) / 2;
    return get(POS, i, j, l, mid, id*2) + get(POS, i, j, mid+1, r, id*2+1);
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> q;
    for (int i = 0 ; i < n ; i++) {
        ll a;
        cin >> a;
        for (int j = 0 ; j < 31 ; j++) {
            update(i, j, (a >> j)&1, 0, n-1, 1);
        }
    }
    while (q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
           
            for (int j = 0 ; j < 31 ; j++) {
                update(x-1, j, (y >> j)&1, 0, n-1, 1);
            }
        } else
         {
            ll l = x - 1, r =y - 1,len = r - l + 1;
            ll res = 0;
            for (ll j = 0 ; j < 31 ; j++) {
                ll one = get(j, l, r, 0, n-1, 1);
                ll zero = len - one;
                if (one < zero) res += (1ll << j);
                
            }
            cout << res << "\n";
        }
    }
    // return 0;
}