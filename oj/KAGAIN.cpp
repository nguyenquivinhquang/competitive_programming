#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;
const int N = 30009;
int D[N], L[N], n, a[N], R[N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int top = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        D[0] = 0;
        for (int i = 1; i <= n; ++i) {
            while (top > 0 && a[D[top]] >= a[i]) --top;
            L[i] = D[top] + 1;
            D[++top] = i;
        }
        D[0] = n + 1;
        top = 0;
        for (int i = n; i >= 1; i--) {
            while (top > 0 && a[D[top]] >= a[i]) top--;
            R[i] = D[top] - 1;
            D[++top] = i;
        }
        ll res = -1e9, ss, ee;
        for (int i = 1; i <= n; i++) {
            if (res < (R[i] - L[i] + 1 ) * a[i]) {
                res = (R[i] - L[i] + 1 ) * a[i];
                ss = L[i], ee = R[i];
            }
        }
        cout << res  << " " << ss << " " << ee << "\n";
    }
}
