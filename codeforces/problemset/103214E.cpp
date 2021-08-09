/*
    XXV Spain Olympiad in Informatics
    Final, day 1
    objetos
*/

#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 2000000;

using namespace std;
int n, a[N], p[N], prefix_p[N], prefix_mul[N];
ll get_sum_p(int l, int r) {
    if (r < l) return 0;
    return prefix_p[r] - prefix_p[l - 1];
}
ll get_sum_mul(int l, int r) {
    if (r < l) return 0;
    return prefix_mul[r] - prefix_mul[l - 1];
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix_p[i] = prefix_p[i-1] + p[i];
        prefix_mul[i] = prefix_mul[i - 1] + p[i] * a[i];
    } 
    ll res = 1e18, index = 0;
    for (int i = 1; i <= n; i++) {
        ll  smaller = - get_sum_mul(1, i - 1) + a[i] * get_sum_p(1, i - 1);
        ll greater = get_sum_mul(i + 1, n) - a[i] * get_sum_p(i+1,n);
        if (smaller + greater < res) {
            res = smaller + greater;
            index = i;
        }
    }
    cout << index-1;
}
