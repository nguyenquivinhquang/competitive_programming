#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int a[N], n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll cost = 0;
    for (int i = 1; i < n; i++) {
        ll M = a[i], index = i;
        for (int j = i; j <= n; j++) 
            if (a[j] < M ) {
                M = a[j];
                index = j;
            }
        cost += index - i + 1;
        reverse(a + i, a  + index + 1);
    }
    cout << cost << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    for (int i = 1 ; i <= testcase; i++) {
        cout << "Case #" << i <<": ";
        solve();
    }
}
