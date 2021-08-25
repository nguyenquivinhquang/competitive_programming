#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 100009;

using namespace std;
int n, m;
int a[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        if (a[i] + a[i - 1] > m) {
            cout << i - 1;
            return 0;
        }
    }
    cout << n;
}
