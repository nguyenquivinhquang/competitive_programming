//https://open.kattis.com/problems/dvds
#include <bits/stdc++.h>
using namespace std;
const int N = 1000009;
int n, m, a[N], dp[N];


void solve() {
    cin >> n;
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == st.top() + 1)
            st.push(a[i]);
    }

    cout << n - st.size() + 1 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
