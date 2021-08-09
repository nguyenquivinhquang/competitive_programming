#include <bits/stdc++.h>


using namespace std;
int n, k;
long long res = 0;
unordered_map <long long, int> trace;

void solve() {
    int temp;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        res += trace[k - temp * temp];
        trace[temp]++;
    }
    cout << res;
}
signed main() {
//    freopen("1.out", "r", stdin);
    ios_base::sync_with_stdio(false);
    solve();
}

