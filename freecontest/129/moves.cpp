#include <bits/stdc++.h>
#define int ll 
#define ll long long
#define pp pair<int, int>

const int N = 2000;

using namespace std;

int n, a[N], d;
ll sum = 0;

void solve() {
    cin >> n >> d;
    sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    
    for (int i = 1; i <= n; i+=2) {
        sum -= d;
    }
    if (sum <= 0)
        cout << "YES\n";
    else cout << "NO\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
